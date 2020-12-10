#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Window.h"

namespace Anacardia
{
	class ANACARDIA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& event);
		bool OnWindowClose(WindowCloseEvent& event);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// Defined by client
	Application* CreateApplication();
}