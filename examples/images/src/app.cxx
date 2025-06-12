/* app.cxx */
#include "app.hpp"
#include "bismuth/core/image.hpp"
#include "bismuth/core/graphics.hpp"
#include "bismuth/misc/color.hpp"
#include "bismuth/sdl/sdlinterface.hpp"

using namespace bismuth;
using namespace bismuth::misc;

App::App()
{
	m_iWidth = 800;
	m_iHeight = 600;
	m_sTitle = "Images Demo";
}

App::~App()
{
}

bool App::InitHook()
{
	Graphics *graphics = static_cast<Graphics *>(GetInterface()->GetGraphics());
	if (!graphics)
	{
		SDL_Log("graphics not available");
		return false;
	}

	if (!graphics->LoadImage(m_cubeImage, "assets/cube.png"))
	{
		SDL_Log("failed to load assets/cube.png");
		return false;
	}

	return true;
}

void App::Frame(Graphics *theGraphics, float deltaTime)
{
	theGraphics->DrawImage(m_cubeImage, 100, 100);

	misc::Rect src{0, 0, 128, 128};
	misc::Rect dest{300, 100, 256, 256};
	theGraphics->DrawImageEx(m_cubeImage, src, dest, 45.0f, nullptr, SDL_FLIP_NONE, misc::Red);
}
