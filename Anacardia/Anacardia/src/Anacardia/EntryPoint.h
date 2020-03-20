#pragma once
#include "Core.h"
#include "Application.h"
#include <memory>

#ifdef ANACARDIA_PLATFORM_WINDOWS

extern ANACARDIA::Application* ANACARDIA::CreateApplication();

int main(int argc, char* argv[])
{
	ANACARDIA::Application* app = ANACARDIA::CreateApplication();
	app->Run();
	delete app;
}

#endif