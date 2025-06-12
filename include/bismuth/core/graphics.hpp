/* core/graphics.hpp */
#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include "core/base.hpp"
#include "core/interface.hpp"
#include "core/image.hpp"
#include "misc/color.hpp"
#include "misc/rect.hpp"

#include <SDL3/SDL.h>

namespace bismuth
{

class AppBase;
class Interface;
class Image;

class Graphics
{
  public:
	Graphics();
	virtual ~Graphics();

	virtual bool Initialize(SDL_Renderer *theRenderer);
	virtual void FillRect(int theX, int theY, int theWidth, int theHeight);
	virtual void FillRect(misc::Rect theRect);
	virtual void SetDrawColor(misc::Color theColor);
	virtual void DrawLine(int theX, int theY, int theX2, int theY2);
	virtual void DrawImage(const Image &image, int x, int y);
	virtual bool LoadImage(Image &image, const std::string &path);
	void DrawImageEx(const Image &image, const misc::Rect &srcRect, const misc::Rect &destRect,
					 float rotationDegrees = 0.0f, const SDL_FPoint *center = nullptr,
					 SDL_FlipMode flip = SDL_FLIP_NONE, misc::Color tint = misc::White);

	SDL_Renderer *GetRenderer() const
	{
		return m_pRenderer;
	}

  private:
	SDL_Renderer *m_pRenderer;
};

} // namespace bismuth

#endif // GRAPHICS_HPP