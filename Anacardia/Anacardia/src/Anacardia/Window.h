#pragma once
#include "pch.h"
#include "Core.h"
#include "Events/Event.h"
#include <functional>

namespace Anacardia
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Anacardia Engine",
					unsigned int width = 1280,
					unsigned int height = 720) 
			: Title(title), Width(width), Height(height)
		{ }
	};

	class ANACARDIA_API Window
	{
	public:
		using EventCallBackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window Attributes
		virtual void SetEventCallback(const EventCallBackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual void IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}
