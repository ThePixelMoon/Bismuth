/* src/app.hpp */
#ifndef APP_HPP
#define APP_HPP
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include "bismuth/core/base.hpp"
#include "bismuth/misc/color.hpp"

namespace bismuth
{

class App : public AppBase
{
public:
    App();
    virtual ~App();

    virtual void Frame(Graphics *theGraphics, float deltaTime) override;

private:
	float x = 100.f, y = 100.f;
	float vx = 200.f, vy = 200.f;
	int boxSize = 100;
	misc::Color color = misc::Color(255, 255, 0, 255);
};

} // namespace bismuth

#endif // APP_HPP