/* core/base.hpp */
#ifndef BASE_HPP
#define BASE_HPP
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include "core/interface.hpp"
#include "core/graphics.hpp"
#include "core/input.hpp"

#include <string>

enum class State
{
    Uninitialized,
    Initialized,
    Running,
    Error
};

namespace bismuth
{

class Interface;
class Graphics;
class Input;

class AppBase
{
public:
    AppBase();
    virtual ~AppBase();

    virtual bool Initialize();
    virtual Interface *CreateInterface();

    virtual void Frame(Graphics *theGraphics, float deltaTime);

    // variables, and shit..
    int m_iWidth, m_iHeight;
	bool m_bIsRunning;
	std::string m_sTitle;

    Input *m_pInput;

protected:
	State m_state;
    Interface *m_pInterface;
};

} // namespace bismuth

#endif // BASE_HPP