#include "pch.h"
#include "WindowsWindow.h"

namespace Anacardia
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int errorCode, const char* description)
	{
		ANACARDIA_CORE_ERROR("GLFW Error [code {0}]: {1}", errorCode, description);
	}

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
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		m_Data.VSync = true;

		ANACARDIA_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			ANACARDIA_CORE_ASSERT(success, "GLFW Successfully Initialized", "GLFW could not be initialized!");
			s_GLFWInitialized = true;
			glfwSetErrorCallback(GLFWErrorCallback);
		}

		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		this->SetVSync(true);

		// Set event callbacks
		glfwSetWindowSizeCallback;

		// Mouse callbacks
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x_cord, double y_cord) 
		{

		});
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
		{
		});
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{

		});

		// Keyboard callbacks
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
		});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int codepoint)
		{


		});
		
	}

	void WindowsWindow::OnUpdate()
	{

	}

	unsigned int WindowsWindow::GetWidth() const
	{
		return m_Data.Width;
	}

	unsigned int WindowsWindow::GetHeight() const
	{
		return m_Data.Height;
	}

	void WindowsWindow::SetEventCallback(const EventCallBackFn& callback)
	{

	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}
		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}
}