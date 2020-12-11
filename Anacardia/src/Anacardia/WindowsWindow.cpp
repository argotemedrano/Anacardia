#include "pch.h"
#include "WindowsWindow.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/ApplicationEvent.h"

namespace Anacardia
{
	static bool s_GLFWInitialized = false;

	GLFWwindow* WindowsWindow::m_Window = nullptr;

	static void GLFWErrorCallback(int errorCode, const char* description)
	{
		ANACARDIA_CORE_ERROR("[GLFW Error <{0}>]: {1}", errorCode, description);
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

		if (m_Window != nullptr)
		{
			ANACARDIA_ERROR("Window already created!");
			return;
		}
		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		this->SetVSync(true);

		// Window Application Events
		// Set event callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;
			WindowResizeEvent event(width, height);
			data.EventCallBack(event);
		});
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallBack(event);
		});

		// Mouse callbacks
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x_cord, double y_cord) 
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event(x_cord, y_cord);
			data.EventCallBack(event);
		});
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event(xoffset, yoffset);
			data.EventCallBack(event);
		});
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			if (action == GLFW_PRESS)
			{
				MouseButtonPressedEvent event(button);
			}
			else if (action == GLFW_RELEASE)
			{
				MouseButtonReleasedEvent event(button);
			}
		});

		// Keyboard callbacks
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			if (action == GLFW_PRESS)
			{
				KeyPressEvent event(key, 0);
				data.EventCallBack(event);
			}
			else if (action == GLFW_RELEASE)
			{
				KeyReleasedEvent event(key);
				data.EventCallBack(event);
			}
			else if (action == GLFW_REPEAT)
			{
				KeyPressEvent event(key, 1);
				data.EventCallBack(event);
			}
		});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int codepoint)
		{


		});
		
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
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
		m_Data.EventCallBack = callback;
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

	void* Window::GetNativeWindow()
	{
		return WindowsWindow::GetNativeWindow();
	}

	void* WindowsWindow::GetNativeWindow()
	{
		return m_Window;
	}
}