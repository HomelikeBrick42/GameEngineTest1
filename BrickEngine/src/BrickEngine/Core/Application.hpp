#pragma once

#include "BrickEngine/Core/Base.hpp"

namespace BrickEngine {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
