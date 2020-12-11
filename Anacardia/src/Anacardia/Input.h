#pragma once

#include "pch.h"
#include "Core.h"

namespace Anacardia
{
	/*
	* Static (global) singular input manager
	* here are two options:
	* 1) Having a single input manager that polls inputs from
	  the current active window.
	* 2) Having multiple input managers for different windows.
	* 
	* Interface implemented per platform
	*/
	class ANACARDIA_API Input
	{
	public:
		static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }
		static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
		virtual std::pair<float, float> GetMousePosImpl() = 0;
	private:
		static Input* s_Instance;
	};
}