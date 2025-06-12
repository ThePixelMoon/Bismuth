/* core/image.cxx */
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "core/image.hpp"
#include "misc/color.hpp"
#include <iostream>

using namespace bismuth;

Image::Image() : m_texture(nullptr), m_width(0), m_height(0), m_filePath("")
{
}

Image::~Image()
{
	Unload();
}

bool Image::LoadFromFile(const std::string &filePath, SDL_Renderer *renderer)
{
	Unload();

	int channels = 0;
	unsigned char *pixels = stbi_load(filePath.c_str(), &m_width, &m_height, &channels, STBI_rgb_alpha);
	if (!pixels)
	{
		SDL_Log("stb_image failed to load %s: %s", filePath.c_str(), stbi_failure_reason());
		return false;
	}

	SDL_Surface *surface = SDL_CreateSurfaceFrom(m_width, m_height, SDL_PIXELFORMAT_RGBA32, pixels, m_width * 4);
	if (!surface)
	{
		SDL_Log("SDL_CreateSurfaceFrom failed: %s", SDL_GetError());
		stbi_image_free(pixels);
		return false;
	}

	m_texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_DestroySurface(surface);
	stbi_image_free(pixels);

	if (!m_texture)
	{
		SDL_Log("SDL_CreateTextureFromSurface failed: %s", SDL_GetError());
		return false;
	}

	m_filePath = filePath;
	return true;
}

void Image::Unload()
{
	if (!m_texture)
		return;

	SDL_DestroyTexture(m_texture);
	m_texture = nullptr;
	m_width = m_height = 0;
	m_filePath.clear();
}

void Image::Draw(SDL_Renderer *renderer, int x, int y) const
{
	if (!m_texture)
		return;
	SDL_FRect dest = {(float)x, (float)y, (float)m_width, (float)m_height};
	SDL_RenderTexture(renderer, m_texture, nullptr, &dest);
}

void Image::Draw(SDL_Renderer *renderer, const misc::Rect &srcRect, const misc::Rect &destRect) const
{
	if (!m_texture)
		return;

	SDL_FRect src = {(float)srcRect.m_x, (float)srcRect.m_y, (float)srcRect.m_width, (float)srcRect.m_height};
	SDL_FRect dest = {(float)destRect.m_x, (float)destRect.m_y, (float)destRect.m_width, (float)destRect.m_height};
	SDL_RenderTexture(renderer, m_texture, &src, &dest);
}

void Image::DrawEx(SDL_Renderer *renderer, const misc::Rect &srcRect, const misc::Rect &destRect, float rotationDegrees,
				   const SDL_FPoint *center, SDL_FlipMode flip, misc::Color tint) const
{
	if (!m_texture || !renderer)
		return;

	SDL_SetTextureColorMod(m_texture, tint.m_r, tint.m_g, tint.m_b);
	SDL_SetTextureAlphaMod(m_texture, tint.m_a);

	SDL_FRect sr = {static_cast<float>(srcRect.m_x), static_cast<float>(srcRect.m_y),
					static_cast<float>(srcRect.m_width), static_cast<float>(srcRect.m_height)};
	SDL_FRect dr = {static_cast<float>(destRect.m_x), static_cast<float>(destRect.m_y),
					static_cast<float>(destRect.m_width), static_cast<float>(destRect.m_height)};

	// if no center provided, SDL will default to (w/2, h/2)
	bool success =
		SDL_RenderTextureRotated(renderer, m_texture, &sr, &dr, static_cast<double>(rotationDegrees), center, flip);

	if (!success)
		SDL_Log("SDL_RenderTextureRotated failed: %s", SDL_GetError());
}
