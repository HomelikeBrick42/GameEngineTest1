#include "brickpch.hpp"
#include "BrickEngine/Core/Application.hpp"

namespace BrickEngine {

	Application::Application()
	{
		Log::Init();
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (true);
	}

}
