/* app.cxx */
#include "app.hpp"
#include "bismuth/misc/color.hpp"
#include "bismuth/core/input.hpp"
#include "bismuth/core/image.hpp"
#include "bismuth/sdl/sdlinterface.hpp"

using namespace bismuth;
using namespace bismuth::misc;

App::App()
{
	m_iWidth = 800;
	m_iHeight = 600;
	m_sTitle = "Moving Square Demo";
}

App::~App()
{
}

void App::Frame(Graphics *theGraphics, float deltaTime)
{
	if (m_pInput->IsKeyDown(KeyCode::Space))
	{
		x += vx * deltaTime;
		y += vy * deltaTime;
	}

	if (x <= 0 || x + boxSize >= m_iWidth)
	{
		vx = -vx;
		color = Color(rand() % 255, rand() % 255, rand() % 255, 255);
	}
	if (y <= 0 || y + boxSize >= m_iHeight)
	{
		vy = -vy;
		color = Color(rand() % 255, rand() % 255, rand() % 255, 255);
	}

	theGraphics->SetDrawColor(color);
	theGraphics->FillRect(x, y, boxSize, boxSize);
}
