/* core/interface.hpp */
#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include "core/base.hpp"
#include <string>

namespace bismuth
{

class AppBase;

class Interface
{
  public:
	virtual ~Interface(){};

	virtual bool Initialize(AppBase *m_appBase) = 0;
	virtual bool CreateWindow(std::string m_title) = 0;
};

} // namespace bismuth

#endif // INTERFACE_HPP