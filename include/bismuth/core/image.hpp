/* core/image.hpp */
#ifndef IMAGE_HPP
#define IMAGE_HPP
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include <string>
#include <SDL3/SDL.h>
#include "misc/rect.hpp"
#include "misc/color.hpp"

namespace bismuth
{

namespace misc
{
class Color;
} // namespace bismuth::misc

class Image
{
  public:
	Image();
	~Image();

	bool LoadFromFile(const std::string &filePath, SDL_Renderer *renderer);
	void Unload();

	void Draw(SDL_Renderer *renderer, int x, int y) const;
	void Draw(SDL_Renderer *renderer, const misc::Rect &srcRect, const misc::Rect &destRect) const;

	void DrawEx(SDL_Renderer *renderer, const misc::Rect &srcRect, const misc::Rect &destRect, float rotationDegrees,
				const SDL_FPoint *center = nullptr, SDL_FlipMode flip = SDL_FLIP_NONE,
				misc::Color tint = misc::White) const;

	int GetWidth() const
	{
		return m_width;
	}
	int GetHeight() const
	{
		return m_height;
	}
	bool IsLoaded() const
	{
		return m_texture != nullptr;
	}
	const std::string &GetFilePath() const
	{
		return m_filePath;
	}

  private:
	SDL_Texture *m_texture;
	int m_width;
	int m_height;
	std::string m_filePath;
};

} // namespace bismuth

#endif // IMAGE_HPP