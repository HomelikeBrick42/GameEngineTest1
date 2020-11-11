#include "brickpch.hpp"
#include "BrickEngine/Scene/Scene.hpp"

#include "BrickEngine/Scene/Entity.hpp"

namespace BrickEngine {

    Scene::Scene()
    {
    }

    Scene::~Scene()
    {
    }

    Entity Scene::CreateEntity(const std::string& name)
    {
        Entity entity(m_Registry.create(), this);
        return entity;
    }

    void Scene::DestroyEntity(Entity entity)
    {
        if (entity.m_Scene == this)
            m_Registry.destroy(entity);
    }

}
