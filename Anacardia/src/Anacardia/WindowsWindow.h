#pragma once
#include "pch.h"
#include "Window.h"
#include "GFLW/gflw3.h"

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
		bool IsVSync() const override;

		static Window* Create(const WindowProps& props = WindowProps());
	private:
		void Init(const WindowProps& props);
		void Shutdown();
		GFLWwindow* m_Window;
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			EventCallBackFn EventCallBack;
		};
		WindowData m_Data;

	};
}

