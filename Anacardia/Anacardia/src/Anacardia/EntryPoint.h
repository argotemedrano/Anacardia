#pragma once


#ifdef ANACARDIA_PLATFORM_WINDOWS

extern ANACARDIA::Application* ANACARDIA::CreateApplication();

int main(int argc, char* argv[])
{
	Anacardia::Log::Init();
	ANACARDIA::Application* app = ANACARDIA::CreateApplication();
	app->Run();
	delete app;
}

#endif	