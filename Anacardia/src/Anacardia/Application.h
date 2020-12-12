#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Window.h"
#include "LayerStack.h"

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
		static Application* Get() { return s_Instance; }
		static void SetInstance(Application* instance) { s_Instance = instance; }
		Window& GetWindow() { return *m_Window; }
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		static Application* s_Instance;
		LayerStack m_LayerStack;
	};

	// Defined by client
	Application* CreateApplication();
}