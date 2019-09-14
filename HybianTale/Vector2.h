#pragma once
#include <iostream>
struct Vector2
{
public:
	Vector2();
	Vector2(const float& x, const float& y);

	float x, y;

	Vector2& add(const Vector2& other);
	Vector2& subtract(const Vector2& other);
	Vector2& multiply(const Vector2& other);
	Vector2& divide(const Vector2& other);

	friend Vector2& operator+(Vector2 left, const Vector2& right);
	friend Vector2& operator-(Vector2 left, const Vector2& right);
	friend Vector2& operator*(Vector2 left, const Vector2& right);
	friend Vector2& operator/(Vector2 left, const Vector2& right);

	Vector2 operator==(const Vector2& other) const;
	Vector2 operator!=(const Vector2& other) const;

	~Vector2();


	friend std::ostream& operator<<(std::ostream& stream, const Vector2& vector);
};

