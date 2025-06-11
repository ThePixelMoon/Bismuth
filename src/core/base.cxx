/* core/base.cxx */
#include "core/base.hpp"
#ifdef _USE_SDL
#include "sdl/sdlinterface.hpp"
#endif

using namespace bismuth;

AppBase::AppBase()
{
	m_state = State::Uninitialized;
	m_pInterface = nullptr;
	m_pInput = nullptr;

	// if we dont have a normal width & height,
	// set it to the default one
	m_iWidth = 640;
	m_iHeight = 480;

	m_sTitle = "Untitled";
	m_bIsRunning = false;
}

AppBase::~AppBase()
{
	m_state = State::Uninitialized;
	m_pInterface = nullptr;
	m_pInput = nullptr;
}

bool AppBase::Initialize()
{
	m_state = State::Running;
	m_pInput = new Input();

	CreateInterface(); // initialize the interface

	// this function is the same for all. if you dare to
	// change this, you are a horrible person.
	m_pInterface->Initialize(this);

	return true;
}

void AppBase::Frame(Graphics *theGraphics, float deltaTime)
{
}

Interface *AppBase::CreateInterface()
{
#ifdef _USE_SDL
	m_pInterface = new SDLInterface();
#else
#error "No interface. Why?"
#endif

	return m_pInterface;
}
