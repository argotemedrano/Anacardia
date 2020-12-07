#include <Anacardia.h>

class Sandbox : public Anacardia::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Anacardia::Application* Anacardia::CreateApplication()
{
	return new Sandbox();
}