/* app.cxx */
#include "app.hpp"
#include "bismuth/misc/color.hpp"
#include "bismuth/core/input.hpp"

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
    // draw the moving rectangle
    theGraphics->SetDrawColor(color);
    theGraphics->FillRect(x, y, boxSize, boxSize);

	if (m_pInput->IsKeyDown(KeyCode::Space))
	{
		// multiply velocity by deltaTime to get frame-rate independent movement

        x += vx * deltaTime;
		y += vy * deltaTime;
	}

    bool bounced = false;

    if (x <= 0 || x + boxSize >= m_iWidth)
    {
        vx = -vx;
        bounced = true;
    }
    if (y <= 0 || y + boxSize >= m_iHeight)
    {
        vy = -vy;
        bounced = true;
    }

    if (bounced)
    {
        color = Color(
            100 + rand() % 156,
            100 + rand() % 156,
            100 + rand() % 156,
            255
        );
    }
}