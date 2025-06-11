/* core/interface.hpp */
#ifndef SDLINTERFACE_HPP
#define SDLINTERFACE_HPP
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include "core/interface.hpp"
#include "core/graphics.hpp"

#include <SDL3/SDL.h>

namespace bismuth
{
    
class Graphics;

class SDLInterface : public Interface
{
public:
    SDLInterface();
    virtual ~SDLInterface();

    virtual bool Initialize(AppBase *theAppBase);
	virtual bool CreateWindow(std::string m_title);

    virtual void DoLoop(); // hacky hack for emscripten

protected:
    AppBase *m_appBase;
    SDL_Renderer *m_pRenderer;
	SDL_Window *m_pWindow;

    Graphics *m_pGraphics;
};

} // namespace bismuth

#endif // SDLINTERFACE_HPP