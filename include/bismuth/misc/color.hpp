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
    Color(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 255)
        : m_r(r), m_g(g), m_b(b), m_a(a) {}

    virtual ~Color() {}

    uint8_t m_r;
    uint8_t m_g;
    uint8_t m_b;
    uint8_t m_a;
};

} // namespace bismuth::misc

#endif // COLOR_HPP