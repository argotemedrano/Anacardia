#include "pch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

Anacardia::Application::Application()
{
	//Anacardia::Log::Init();
	m_Window = std::unique_ptr<Window>(Window::Create());
}

Anacardia::Application::~Application()
{

}

void Anacardia::Application::Run()
{
	ANACARDIA_CORE_INFO("Started Anacardia Core Logger: ", Anacardia::Log::GetCoreLogger()->name());
	ANACARDIA_INFO("Started Anacardia Client Logger: ", Anacardia::Log::GetClientLogger()->name());
	while (m_Running)
	{
		m_Window->OnUpdate();
	}
}