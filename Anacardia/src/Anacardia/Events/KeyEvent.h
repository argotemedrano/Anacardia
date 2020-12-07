#pragma once

#include "pch.h"
#include "Event.h"


namespace Anacardia
{
	class ANACARDIA_API KeyEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategory::EventCategoryKeyboard)
	};

	class ANACARDIA_API KeyPressEvent : public KeyEvent
	{
	public:
		KeyPressEvent(bool repeat)
			: m_Repeat(repeat)
		{}
		EVENT_CLASS_TYPE(EventType::KeyPressed)
	private:
		bool m_Repeat = false;
	};

	class ANACARDIA_API KeyReleasedEvent : public KeyEvent
	{
	public:
		EVENT_CLASS_TYPE(EventType::KeyReleased)
	};
}