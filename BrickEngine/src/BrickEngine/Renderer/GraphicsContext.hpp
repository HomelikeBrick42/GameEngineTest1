#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Core/Window.hpp"

namespace BrickEngine {

	class GraphicsContext
	{
	public:
		virtual ~GraphicsContext() = default;

		virtual void Bind() = 0;
		virtual void SwapBuffers() = 0;

		static Scope<GraphicsContext> Create(void* windowHandle);
	protected:
		GraphicsContext() = default;
	};

}
