#include <BrickEngine.hpp>
#include <BrickEngine/EntryPoint.hpp>

using namespace BrickEngine;

class Sandbox : public Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
private:
};

Application* BrickEngine::CreateApplication()
{
	return new Sandbox();
}
