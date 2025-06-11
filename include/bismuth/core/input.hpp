/* core/input.hpp */
#ifndef INPUT_HPP
#define INPUT_HPP
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include <SDL3/SDL.h>
#include <unordered_map>
#include "core/keycode.hpp"

namespace bismuth
{

class Input
{
public:
    Input();
    ~Input();

    void Update(const SDL_Event &event);
    void Reset();

    bool IsKeyDown(KeyCode key) const;
    bool IsKeyPressed(KeyCode key) const;
    bool IsKeyReleased(KeyCode key) const;

private:
    std::unordered_map<KeyCode, bool> m_keyDown;
    std::unordered_map<KeyCode, bool> m_keyPressed;
    std::unordered_map<KeyCode, bool> m_keyReleased;
};

} // namespace bismuth

#endif // INPUT_HPP
