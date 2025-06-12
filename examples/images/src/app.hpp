/* src/app.hpp */
#ifndef APP_HPP
#define APP_HPP
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include "bismuth/core/base.hpp"
#include "bismuth/core/image.hpp"

namespace bismuth
{

class App : public AppBase
{
  public:
	App();
	virtual ~App();

	bool InitHook() override;
	void Frame(Graphics *theGraphics, float deltaTime) override;

  private:
	Image m_cubeImage;
};

} // namespace bismuth

#endif // APP_HPP