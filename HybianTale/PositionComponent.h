#pragma once
#include "Components.h"
#include "Vector2.h"

class TransformComponent : public Component
{
public:
	TransformComponent(const float x, const float y, int width, int height, float scale)
	{
		m_position.x = x;
		m_position.y = y;
		m_velocity.x = 0;
		m_velocity.y = 0;

		m_width = width;
		m_height = height;
		m_scale = scale;
	}

	TransformComponent()
	{
		m_position.x = 0;
		m_position.y = 0;
		m_velocity.x = 0;
		m_velocity.y = 0;
		m_width = 0;
		m_height = 0;
		m_scale = 0;
	}

	void Update(const float& delta)
	{
		m_oldPosition.x = m_position.x;
		m_oldPosition.y = m_position.y;

		m_position.x += m_velocity.x * (m_transformSpeed * delta);
		m_position.y += m_velocity.y * (m_transformSpeed * delta);
	}

	Vector2 m_position;
	Vector2 m_oldPosition;
	Vector2 m_velocity;

	int m_width, m_height;
	float m_scale;

	float m_transformSpeed;
private:
};