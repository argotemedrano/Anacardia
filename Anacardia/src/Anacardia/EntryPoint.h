#pragma once


#ifdef ANACARDIA_PLATFORM_WINDOWS

extern Anacardia::Application* Anacardia::CreateApplication();

int main(int argc, char* argv[])
{
	Anacardia::Log::Init();
	Anacardia::Application* app = Anacardia::CreateApplication();
	app->Run();
	delete app;
}

#endif	