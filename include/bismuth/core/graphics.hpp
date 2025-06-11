/* core/graphics.hpp */
#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include "core/base.hpp"
#include "core/interface.hpp"
#include "misc/color.hpp"
#include "misc/rect.hpp"

#include <SDL3/SDL.h>

namespace bismuth
{
    
class AppBase;
class Interface;

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

  private:
	SDL_Renderer *m_pRenderer;
};

} // namespace bismuth

#endif // GRAPHICS_HPP