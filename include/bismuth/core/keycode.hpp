/* core/keycode.hpp */
#ifndef KEYCODE_HPP
#define KEYCODE_HPP
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include <SDL3/SDL.h>
#include <unordered_map>

namespace bismuth
{

enum class KeyCode : int
{
    Unknown = SDL_SCANCODE_UNKNOWN,
    A = SDL_SCANCODE_A,
    B = SDL_SCANCODE_B,
    C = SDL_SCANCODE_C,
    D = SDL_SCANCODE_D,
    E = SDL_SCANCODE_E,
    F = SDL_SCANCODE_F,
    G = SDL_SCANCODE_G,
    H = SDL_SCANCODE_H,
    I = SDL_SCANCODE_I,
    J = SDL_SCANCODE_J,
    K = SDL_SCANCODE_K,
    L = SDL_SCANCODE_L,
    M = SDL_SCANCODE_M,
    N = SDL_SCANCODE_N,
    O = SDL_SCANCODE_O,
    P = SDL_SCANCODE_P,
    Q = SDL_SCANCODE_Q,
    R = SDL_SCANCODE_R,
    S = SDL_SCANCODE_S,
    T = SDL_SCANCODE_T,
    U = SDL_SCANCODE_U,
    V = SDL_SCANCODE_V,
    W = SDL_SCANCODE_W,
    X = SDL_SCANCODE_X,
    Y = SDL_SCANCODE_Y,
    Z = SDL_SCANCODE_Z,

    Space = SDL_SCANCODE_SPACE,
    Enter = SDL_SCANCODE_RETURN,
    Escape = SDL_SCANCODE_ESCAPE,
    Left = SDL_SCANCODE_LEFT,
    Right = SDL_SCANCODE_RIGHT,
    Up = SDL_SCANCODE_UP,
    Down = SDL_SCANCODE_DOWN,
};

inline SDL_Scancode ToSDLScancode(KeyCode key)
{
    return static_cast<SDL_Scancode>(key);
}

inline KeyCode FromSDLScancode(SDL_Scancode scancode)
{
    return static_cast<KeyCode>(scancode);
}

} // namespace bismuth

namespace std
{
    template<>
    struct hash<bismuth::KeyCode>
    {
        std::size_t operator()(const bismuth::KeyCode& k) const noexcept
        {
            return std::hash<int>()(static_cast<int>(k));
        }
    };
} // namespace std

#endif // KEYCODE_HPP