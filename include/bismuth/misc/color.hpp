/* misc/color.hpp */
#ifndef COLOR_HPP
#define COLOR_HPP
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include <cstdint>

namespace bismuth::misc
{

class Color
{
  public:
	constexpr Color(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 255)
	    : m_r(r), m_g(g), m_b(b), m_a(a)
	{
	}

	constexpr ~Color() = default;

	uint8_t m_r;
	uint8_t m_g;
	uint8_t m_b;
	uint8_t m_a;
};

inline constexpr Color White     = Color(255, 255, 255, 255);
inline constexpr Color Black     = Color(0, 0, 0, 255);
inline constexpr Color Red       = Color(255, 0, 0, 255);
inline constexpr Color Green     = Color(0, 255, 0, 255);
inline constexpr Color Blue      = Color(0, 0, 255, 255);
inline constexpr Color Yellow    = Color(255, 255, 0, 255);
inline constexpr Color Cyan      = Color(0, 255, 255, 255);
inline constexpr Color Magenta   = Color(255, 0, 255, 255);
inline constexpr Color Orange    = Color(255, 165, 0, 255);
inline constexpr Color Purple    = Color(128, 0, 128, 255);
inline constexpr Color Pink      = Color(255, 192, 203, 255);
inline constexpr Color Brown     = Color(139, 69, 19, 255);
inline constexpr Color Gray      = Color(128, 128, 128, 255);
inline constexpr Color LightGray = Color(192, 192, 192, 255);
inline constexpr Color DarkGray  = Color(64, 64, 64, 255);
inline constexpr Color Transparent = Color(0, 0, 0, 0);

} // namespace bismuth::misc

#endif // COLOR_HPP