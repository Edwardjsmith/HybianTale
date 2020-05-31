#pragma once
#include <iostream>
struct Vector2
{
public:
	Vector2();
	Vector2(const float& x, const float& y);

	float x, y;

	static const Vector2 m_zero;
	static const Vector2 m_up;
	static const Vector2 m_right;

	//functions to allow operation between vectors
	Vector2& Add(const Vector2& other);
	Vector2& Subtract(const Vector2& other);
	Vector2& Multiply(const Vector2& other);
	Vector2& Divide(const Vector2& other);

	//Allow vectors to be multiplied and divided by floats
	Vector2& Multiply(const float& other);
	Vector2& Divide(const float& other);

	//Overload operators to allow them to be used between vectors
	friend Vector2& operator+(Vector2 left, const Vector2& right);
	friend Vector2& operator-(Vector2 left, const Vector2& right);
	friend Vector2& operator*(Vector2 left, const Vector2& right);
	friend Vector2& operator/(Vector2 left, const Vector2& right);

	//Equality operators between vectors
	Vector2 operator==(const Vector2& other) const;
	Vector2 operator!=(const Vector2& other) const;

	//Overload operators to allow them to be used between vectors and floats
	friend Vector2& operator*(Vector2 left, const float& right);
	friend Vector2& operator/(Vector2 left, const float& right);

	static float Distance(const Vector2& posA, const Vector2& posB);

	~Vector2();


	friend std::ostream& operator<<(std::ostream& stream, const Vector2& vector);
};

