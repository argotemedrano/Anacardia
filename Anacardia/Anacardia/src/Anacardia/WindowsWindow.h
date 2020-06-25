#pragma once
#include "pch.h"
#include "Window.h"

namespace Anacardia
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;
		unsigned int GetWidth() const override;
		unsigned int GetHeight() const override;

		void SetEventCallback(const EventCallBackFn& callback) override;
		void SetVSync(bool enabled) override;
		void IsVSync() const override;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}

