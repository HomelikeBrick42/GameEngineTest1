#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Core/Layer.hpp"

namespace BrickEngine {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void Begin();
		void End();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;
	};

}
