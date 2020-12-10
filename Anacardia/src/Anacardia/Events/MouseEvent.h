#pragma once

#include "Event.h"

#include <sstream>

namespace Anacardia
{
	class ANACARDIA_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y)
		{ }

		inline float GetXPos() const
		{
			return m_MouseX;
		}

		inline float GetYPos() const
		{
			return m_MouseY;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: (" << m_MouseX << ", " << m_MouseY << ")";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
		EVENT_CLASS_TYPE(MouseMoved);
	private:
		float m_MouseX, m_MouseY;
	};

	class ANACARDIA_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float x, float y) : m_OffsetX(x), m_OffsetY(y)
		{ }
		inline float GetXOffset() const
		{
			return m_OffsetX;
		}

		inline float GetYOffset() const
		{
			return m_OffsetY;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: (" << m_OffsetX << ", " << m_OffsetY << ")";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
		EVENT_CLASS_TYPE(MouseScrolled);
	private:
		float m_OffsetX, m_OffsetY;
	};

	class ANACARDIA_API MouseButtonEvent : public Event
	{
	public:
		MouseButtonEvent(int button) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonEvent";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
	protected:
		int m_Button;
	};

	class ANACARDIA_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class ANACARDIA_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased);
	};
}