#pragma once

#include "BrickEngine/Core/Base.hpp"

#include <entt/entt.hpp>

namespace BrickEngine {

	class Scene
	{
		friend class Entity;
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name);
		void DestroyEntity(Entity entity);

		void OnUpdate(float dt);
	private:
		entt::registry m_Registry;
	};

}
