#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Events/Event.hpp"
#include "BrickEngine/Core/KeyCodes.hpp"

namespace BrickEngine {

	class Input
	{
	public:
		static void Init();
		static void OnEvent(Event& e);
		static void EndFrame();

		static bool GetKey(KeyCode key);
		static bool GetKeyDown(KeyCode key);
		static bool GetKeyUp(KeyCode key);

		static glm::vec2 GetMousePosition();
		static glm::vec2 GetMouseDelta();

		static glm::vec2 GetMouseScroll();

		static bool GetMouseButton(MouseButton button);
		static bool GetMouseButtonDown(MouseButton button);
		static bool GetMouseButtonUp(MouseButton button);
	};

}
