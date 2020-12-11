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
	*/
	class ANACARDIA_API Input
	{
	public:
		static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }
	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
	private:
		static Input* s_Instance;
	};
}