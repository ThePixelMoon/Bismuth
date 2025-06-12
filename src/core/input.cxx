/* core/input.cxx */
#include "core/input.hpp"
#include "core/event.hpp"

using namespace bismuth;

Input::Input()
{
}

Input::~Input()
{
}

void Input::Reset()
{
	m_keyPressed.clear();
	m_keyReleased.clear();
}

void Input::Update(const SDL_Event &event)
{
	if (event.type == SDL_EVENT_KEY_DOWN && !event.key.repeat)
	{
		KeyCode key = FromSDLScancode(event.key.scancode);
		if (!m_keyDown[key])
		{
			m_keyDown[key] = true;
			m_keyPressed[key] = true;

			Event ev;
			ev.type = EventType::KeyPressed;
			ev.key = static_cast<int>(key);
			m_eventManager.Emit(ev);
		}
	}
	else if (event.type == SDL_EVENT_KEY_UP)
	{
		KeyCode key = FromSDLScancode(event.key.scancode);
		m_keyDown[key] = false;
		m_keyReleased[key] = true;

		Event ev;
		ev.type = EventType::KeyReleased;
		ev.key = static_cast<int>(key);
		m_eventManager.Emit(ev);
	}
}

bool Input::IsKeyDown(KeyCode key) const
{
	auto it = m_keyDown.find(key);
	return it != m_keyDown.end() && it->second;
}

bool Input::IsKeyPressed(KeyCode key) const
{
	auto it = m_keyPressed.find(key);
	return it != m_keyPressed.end() && it->second;
}

bool Input::IsKeyReleased(KeyCode key) const
{
	auto it = m_keyReleased.find(key);
	return it != m_keyReleased.end() && it->second;
}