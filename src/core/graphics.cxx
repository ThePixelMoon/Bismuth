/* core/graphics.cxx */
#include "core/graphics.hpp"
#include "misc/rect.hpp"

using namespace bismuth;
using namespace bismuth::misc;

Graphics::Graphics()
{
	m_pRenderer = nullptr;
}

Graphics::~Graphics()
{
	SDL_DestroyRenderer(m_pRenderer);
}

bool Graphics::Initialize(SDL_Renderer *theRenderer)
{
	m_pRenderer = theRenderer;

	return true;
}

void Graphics::FillRect(int theX, int theY, int theWidth, int theHeight)
{
	Rect mRect = Rect(theX, theY, theWidth, theHeight);
	SDL_FRect temp = ToSDLFRect(mRect);
	SDL_FRect *mSDLFRect = &temp;

	SDL_RenderFillRect(m_pRenderer, mSDLFRect);
}

void Graphics::FillRect(Rect theRect)
{
	FillRect(theRect.m_x, theRect.m_y, theRect.m_width, theRect.m_height);
}

void Graphics::DrawLine(int theX, int theY, int theX2, int theY2)
{
	SDL_RenderLine(m_pRenderer, theX, theY, theX2, theY2);
}

void Graphics::SetDrawColor(Color theColor)
{
	// this is a simple wrapper, nothing else
	SDL_SetRenderDrawColor(m_pRenderer, theColor.m_r, theColor.m_g, theColor.m_b, theColor.m_a);
}