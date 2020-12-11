#include "pch.h"
#include "WindowsInput.h"

#include "Anacardia/Window.h"

namespace Anacardia
{
#ifdef ANACARDIA_PLATFORM_WINDOWS
	Input* Input::s_Instance = new WindowsInput;
#endif
	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Window::GetNativeWindow());
		int state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Window::GetNativeWindow());
		int state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	float WindowsInput::GetMouseXImpl()
	{
		auto [x, y] = GetMousePosImpl();
		return x;
	}

	float WindowsInput::GetMouseYImpl()
	{
		auto [x, y] = GetMousePosImpl();
		return y;
	}

	std::pair<float, float> WindowsInput::GetMousePosImpl()
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Window::GetNativeWindow());
		double x, y;
		glfwGetCursorPos(window, &x, &y);

		return std::make_pair((float)x, (float)y);
	}
}
