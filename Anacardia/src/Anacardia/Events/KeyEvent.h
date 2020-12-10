#pragma once

#include "pch.h"
#include "Event.h"


namespace Anacardia
{
	class ANACARDIA_API KeyEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategory::EventCategoryKeyboard)
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode)
		{
		}
		int m_KeyCode;
	};

	class ANACARDIA_API KeyPressEvent : public KeyEvent
	{
	public:
		KeyPressEvent(int keycode, bool repeat)
			: KeyEvent(keycode),
			  m_Repeat(repeat)
		{}
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		bool m_Repeat = false;
	};

	class ANACARDIA_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode)
		{}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}