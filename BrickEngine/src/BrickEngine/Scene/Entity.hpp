#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Scene/Scene.hpp"

namespace BrickEngine {

	class Entity
	{
		friend class Scene;
	public:
		Entity()
			: m_EntityID(entt::null), m_Scene(nullptr) {}
		Entity(entt::entity id, Scene* scene)
			: m_EntityID(id), m_Scene(scene) {}

		template<typename T, typename... Args>
		T& AddComponent(Args&&... args)
		{
			BRICKENGINE_CORE_ASSERT(!HasComponent<T>(), "Entity already has component!");
			return m_Scene->m_Registry.emplace<T>(m_EntityID, std::forward<Args>(args)...);
		}

		template<typename T>
		T& GetComponent()
		{
			BRICKENGINE_CORE_ASSERT(HasComponent<T>(), "Entity does not have component!");
			return m_Scene->m_Registry.get<T>(m_EntityID);
		}

		template<typename T>
		bool HasComponent()
		{
			return m_Scene->m_Registry.has<T>(m_EntityID);
		}

		template<typename T>
		void DestroyComponent()
		{
			BRICKENGINE_CORE_ASSERT(HasComponent<T>(), "Entity does not have component!");
			return m_Scene->m_Registry.remove<T>(m_EntityID);
		}

		operator bool() const { return m_EntityID != entt::null && m_Scene != nullptr; }
		bool operator==(const Entity& other) const { return m_EntityID == other.m_EntityID && m_Scene == other.m_Scene; }
		bool operator!=(const Entity& other) const { return !(*this == other); }

		operator uint32_t() const { return (uint32_t)m_EntityID; }
		operator entt::entity() const { return m_EntityID; }
	private:
		entt::entity m_EntityID;
		Scene* m_Scene;
	};

}
