#pragma once

#include "Event.h"

#include <sstream>

namespace Anacardia
{
	class ANACARDIA_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int height, unsigned int width)
			: m_Height(height), m_Width(width)
		{ }

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowsResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication)
	private:
		unsigned int m_Height, m_Width;
	};

	class ANACARDIA_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() { }
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		
	};

	class ANACARDIA_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() { }
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ANACARDIA_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() { }
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ANACARDIA_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() { }
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}