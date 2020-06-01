#pragma once
#include "Components.h"

class PositionComponent : public Component
{
public:
	PositionComponent(const float x, const float y)
	{
		m_x = x;
		m_y = y;
	}

	PositionComponent()
	{
		m_x = 0;
		m_y = 0;
	}
	float GetX() { return m_x; }
	float GetY() { return m_y; }

	void SetPosition(const float x, const float y) 
	{  
		m_x = x;
		m_y = y;
	}

private:
	float m_x;
	float m_y;
};