#include <BrickEngine.hpp>
#include <BrickEngine/EntryPoint.hpp>

#include "SandboxLayer.hpp"

using namespace BrickEngine;

class Sandbox : public Application
{
public:
	Sandbox()
	{
		m_SandboxLayer = new SandboxLayer();
		PushLayer(m_SandboxLayer);
	}

	~Sandbox()
	{
	}
private:
	SandboxLayer* m_SandboxLayer = nullptr;
};

Application* BrickEngine::CreateApplication()
{
	return new Sandbox();
}
