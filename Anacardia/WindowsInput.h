#pragma once
#include "Anacardia/Input.h"
#include <GLFW/glfw3.h>

namespace Anacardia
{
	
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode);
		virtual bool IsMouseButtonPressedImpl(int button);
		virtual float GetMouseXImpl();
		virtual float GetMouseYImpl();
		virtual std::pair<float, float> GetMousePosImpl();
	};
}

