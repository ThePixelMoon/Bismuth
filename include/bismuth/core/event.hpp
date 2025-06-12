/* core/event.hpp */
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
#include <type_traits>

namespace bismuth
{

enum class EventType : int
{
	None = 0,
	KeyPressed,
	KeyReleased,
	WindowResized,
	Custom
};

struct EventTypeHash
{
	std::size_t operator()(EventType type) const noexcept
	{
		return static_cast<std::size_t>(static_cast<std::underlying_type_t<EventType>>(type));
	}
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

	void Unsubscribe(EventType type, EventCallbackFn /*callback*/)
	{
		auto &vec = m_listeners[type];
		vec.erase(std::remove_if(vec.begin(), vec.end(),
								 [&](const EventCallbackFn &) {
									 return false; // no-op for now
								 }),
				  vec.end());
	}

	void Emit(const Event &event) const
	{
		if (event.type == EventType::None)
			return;

		auto it = m_listeners.find(event.type);
		if (it != m_listeners.end())
		{
			for (auto &fn : it->second)
				fn(event);
		}
	}

  private:
	std::unordered_map<EventType, std::vector<EventCallbackFn>, EventTypeHash> m_listeners;
};

} // namespace bismuth

#endif // EVENT_HPP
