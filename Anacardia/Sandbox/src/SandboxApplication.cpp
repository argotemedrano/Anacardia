#include <Anacardia.h>

class Sandbox : public ANACARDIA::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

ANACARDIA::Application* ANACARDIA::CreateApplication()
{
	return new Sandbox();
}