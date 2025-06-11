/* misc/rect.hpp */
#ifndef RECT_HPP
#define RECT_HPP
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include <SDL3/SDL.h>

namespace bismuth::misc
{

class Rect
{
  public:
	Rect(int x = 0, int y = 0, int width = 0, int height = 0) : m_x(x), m_y(y), m_width(width), m_height(height)
	{
	}
	virtual ~Rect(){};

	int m_x, m_y;
	int m_width, m_height;
};

inline SDL_Rect ToSDLRect(const Rect &r)
{
	return SDL_Rect{r.m_x, r.m_y, r.m_width, r.m_height};
}

inline SDL_FRect ToSDLFRect(const Rect &r)
{
	return SDL_FRect{(float)r.m_x, (float)r.m_y, (float)r.m_width, (float)r.m_height};
}

} // namespace bismuth::misc

#endif // RECT_HPP