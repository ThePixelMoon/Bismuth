/* sdlinterface.cxx */
#include "sdl/sdlinterface.hpp"
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

using namespace bismuth;

static SDL_InitFlags currentFlags = SDL_INIT_VIDEO;
#ifdef __EMSCRIPTEN__
static SDLInterface *g_sdlInterfaceInstance = nullptr;
#endif

SDLInterface::SDLInterface()
{
	m_appBase = nullptr;
	m_pRenderer = nullptr;
	m_pWindow = nullptr;
	m_pGraphics = nullptr;
}

SDLInterface::~SDLInterface()
{
	m_appBase = nullptr;
	m_pGraphics = nullptr;

	SDL_DestroyRenderer(m_pRenderer);
	SDL_QuitSubSystem(currentFlags);
	SDL_DestroyWindow(m_pWindow);

	SDL_Quit(); // quit my ass!
}

void SDLInterface::DoLoop()
{
	m_appBase->m_pInput->Reset(); // reset current input

	static Uint32 lastTime = SDL_GetTicks();
	Uint32 currentTime = SDL_GetTicks();
	float deltaTime = (currentTime - lastTime) / 1000.0f; // convert ms to seconds
	lastTime = currentTime;

	SDL_Event pEvent;
	while (SDL_PollEvent(&pEvent))
	{
		if (pEvent.type == SDL_EVENT_QUIT)
		{
			m_appBase->m_bIsRunning = false;
#ifdef __EMSCRIPTEN__
			emscripten_cancel_main_loop();
#endif
		}

		m_appBase->m_pInput->Update(pEvent); // and update the input
	}

	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(m_pRenderer);

	m_appBase->Frame(m_pGraphics, deltaTime);

	SDL_RenderPresent(m_pRenderer);
}

#ifdef __EMSCRIPTEN__
static void StaticDoLoop()
{
	if (g_sdlInterfaceInstance)
		g_sdlInterfaceInstance->DoLoop();
}
#endif

bool SDLInterface::Initialize(AppBase *theAppBase)
{
	if (!SDL_Init(currentFlags))
	{
		SDL_Log("SDL_Init failed (%s)", SDL_GetError());
		return false;
	}

	// store the reference to appbase,
	// AND create the window with the
	// title from it
	m_appBase = theAppBase;
	CreateWindow(m_appBase->m_sTitle);

	return true;
}

bool SDLInterface::CreateWindow(std::string m_title)
{
	m_pWindow = SDL_CreateWindow(m_title.c_str(), m_appBase->m_iWidth, m_appBase->m_iHeight, SDL_WINDOW_OPENGL);
	m_pRenderer = SDL_CreateRenderer(m_pWindow, NULL); // let SDL pick the best renderer for us
	// SDL_SetRenderVSync(m_pRenderer, 2);

	m_pGraphics = new Graphics();
	m_pGraphics->Initialize(m_pRenderer);

	m_appBase->m_bIsRunning = true;
#ifdef __EMSCRIPTEN__
	g_sdlInterfaceInstance = this;
	emscripten_set_main_loop(StaticDoLoop, 0, 1);
#else
	while (m_appBase->m_bIsRunning)
	{
		DoLoop();
	}
#endif

	return true;
}
