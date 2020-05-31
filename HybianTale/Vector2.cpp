#include "Vector2.h"

const Vector2 Vector2::m_zero = { 0, 0 };
const Vector2 Vector2::m_up = { 0, 1 };
const Vector2 Vector2::m_right = { 1, 0 };

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(const float & x, const float & y)
{
	this->x = x;
	this->y = y;
}

Vector2 & Vector2::Add(const Vector2 & other)
{
	x += other.x;
	y += other.y;

	return *this;
}

Vector2 & Vector2::Subtract(const Vector2 & other)
{
	x -= other.x;
	y -= other.y;

	return *this;
}

Vector2 & Vector2::Multiply(const Vector2 & other)
{
	x *= other.x;
	y *= other.y;

	return *this;
}

Vector2 & Vector2::Divide(const Vector2 & other)
{
	x /= other.x;
	y /= other.y;

	return *this;
}

Vector2& Vector2::Multiply(const float& other)
{
	x *= other;
	y *= other;

	return *this;
}

Vector2& Vector2::Divide(const float& other)
{
	x /= other;
	y /= other;

	return *this;
}


Vector2  Vector2::operator==(const Vector2 & other) const
{
	return *this == other;
}

Vector2  Vector2::operator!=(const Vector2 & other) const
{
	return *this != other;
}

float Vector2::Distance(const Vector2& posA, const Vector2& posB)
{
	float distX = (posB.x - posA.x) * (posB.x - posA.x);
	float distY = (posB.y - posA.y) * (posB.y - posA.y);

	return sqrt(distX + distY);
}

Vector2::~Vector2()
{
}
Vector2 & operator+(Vector2 left, const Vector2 & right)
{
	return left.Add(right);
}
Vector2 & operator-(Vector2 left, const Vector2 & right)
{
	return left.Subtract(right);
}
Vector2 & operator*(Vector2 left, const Vector2 & right)
{
	return left.Multiply(right);
}
Vector2 & operator/(Vector2 left, const Vector2 & right)
{
	return left.Divide(right);
}

Vector2& operator*(Vector2 left, const float& right)
{
	return left.Multiply(right);
}

Vector2& operator/(Vector2 left, const float& right)
{
	return left.Divide(right);
}
