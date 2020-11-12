#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Scene/Entity.hpp"

namespace BrickEngine {

	class EntityScript
	{
		friend class Scene;
		friend struct NativeScriptComponent;
	public:
		virtual void OnCreate() {}
		virtual void OnDestroy() {}
		virtual void OnUpdate(float dt) {}
	protected:
		template<typename T, typename... Args>
		T& AddComponent(Args&&... args)
		{
			return m_Entity.AddComponent<T>(std::forward<Args>(args)...);
		}

		template<typename T>
		T& GetComponent()
		{
			return m_Entity.GetComponent<T>();
		}

		template<typename T>
		bool HasComponent()
		{
			return m_Entity.HasComponent<T>();
		}

		template<typename T>
		void DestroyComponent()
		{
			return m_Entity.DestroyComponent<T>();
		}
	private:
		Entity m_Entity;
	};

}
