#include "pch.h"
#include "WindowsWindow.h"
#include "Core.h"

namespace Anacardia
{
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& prop)
	{
		return new WindowsWindow(prop);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{

		
	}

	void WindowsWindow::OnUpdate()
	{

	}

	unsigned int WindowsWindow::GetWidth() const
	{

	}

	unsigned int WindowsWindow::GetHeight() const
	{

	}

	void WindowsWindow::SetEventCallback(const EventCallBackFn& callback)
	{

	}

	void WindowsWindow::SetVSync(bool enabled)
	{

	}

	bool WindowsWindow::IsVSync() const
	{

	}
}