/* event.hpp */
#ifndef EVENT_HPP
#define EVENT_HPP
#ifdef _WIN32
#pragma once
#endif

#include <functional>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

namespace bismuth
{

enum class EventType
{
	None = 0,
	KeyPressed,
	KeyReleased,
	WindowResized,
	Custom
};

struct Event
{
	EventType type = EventType::None;

	int key = 0;
	int width = 0, height = 0;
	std::string message;
};

using EventCallbackFn = std::function<void(const Event &)>;

class EventManager
{
  public:
	void Subscribe(EventType type, EventCallbackFn callback)
	{
		m_listeners[type].push_back(std::move(callback));
	}

	void Unsubscribe(EventType type, EventCallbackFn callback)
	{
		auto &vec = m_listeners[type];
		vec.erase(std::remove_if(vec.begin(), vec.end(),
								 [&](const EventCallbackFn &fn) {
									 // TODO: comparing std::function is tricky.
									 return false;
								 }),
				  vec.end());
	}

	void Emit(const Event &event) const
	{
		auto it = m_listeners.find(event.type);
		if (it != m_listeners.end())
		{
			for (const auto &callback : it->second)
			{
				callback(event);
			}
		}
	}

  private:
	std::unordered_map<EventType, std::vector<EventCallbackFn>> m_listeners;
};

} // namespace bismuth

#endif // EVENT_HPP
