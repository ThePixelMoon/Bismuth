/* core/interface.hpp */
#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include "core/base.hpp"
#include "core/graphics.hpp"
#include <string>

namespace bismuth
{

class AppBase;
class Graphics;

class Interface
{
  public:
	virtual ~Interface(){};

	virtual bool Initialize(AppBase *m_appBase) = 0;
	virtual bool CreateWindow(std::string m_title) = 0;

	virtual void DoLoop() = 0; // hacky hack for emscripten

	virtual Graphics *GetGraphics() const = 0;
};

} // namespace bismuth

#endif // INTERFACE_HPP