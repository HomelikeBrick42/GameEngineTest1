#pragma once

#include "pch.hpp"

class RotateScript : public EntityScript
{
public:
	void OnCreate() override
	{
		m_Transform = &GetComponent<TransformComponent>();
	}

	void OnUpdate(float dt) override
	{
		m_Transform->Rotation.x += 35.0f * dt;
		m_Transform->Rotation.y += 25.0f * dt;
	}
private:
	TransformComponent* m_Transform = nullptr;
};

class CameraControllerScript : public EntityScript
{
public:
	void OnCreate() override
	{
		m_Transform = &GetComponent<TransformComponent>();
	}

	void OnUpdate(float dt) override
	{
		float speed = Input::GetKey(KeyCode::LeftShift) ? 25.0f : 5.0f;

		glm::vec3 forward = glm::normalize(glm::vec3(glm::sin(glm::radians(m_Transform->Rotation.y)), 0.0f, glm::cos(glm::radians(m_Transform->Rotation.y))));
		glm::vec3 right = glm::normalize(glm::cross(forward, glm::vec3(0.0f, 1.0f, 0.0f)));

		if (Input::GetKey(KeyCode::W))
			m_Transform->Position -= forward * speed * dt;
		if (Input::GetKey(KeyCode::S))
			m_Transform->Position += forward * speed * dt;
		if (Input::GetKey(KeyCode::A))
			m_Transform->Position += right * speed * dt;
		if (Input::GetKey(KeyCode::D))
			m_Transform->Position -= right * speed * dt;
		if (Input::GetKey(KeyCode::E))
			m_Transform->Position.y += speed * dt;
		if (Input::GetKey(KeyCode::Q))
			m_Transform->Position.y -= speed * dt;

		if (Input::GetKey(KeyCode::Up))
			m_Transform->Rotation.x += 75.0f * dt;
		if (Input::GetKey(KeyCode::Down))
			m_Transform->Rotation.x -= 75.0f * dt;
		if (Input::GetKey(KeyCode::Left))
			m_Transform->Rotation.y += 75.0f * dt;
		if (Input::GetKey(KeyCode::Right))
			m_Transform->Rotation.y -= 75.0f * dt;

		if (Application::Get().GetWindow()->GetMouseLocked())
			m_Transform->Rotation.yx -= Input::GetMouseDelta() * 0.2f;

		m_Transform->Rotation.x = glm::max(glm::min(m_Transform->Rotation.x, 90.0f), -90.0f);
	}
private:
	TransformComponent* m_Transform = nullptr;
};
