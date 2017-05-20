#include "Vector2.h"
#include "iostream"
#include "Vector3.h"

Vector2::Vector2(float vx, float vy)
{
	x = vx;
	y = vy;
}

Vector2::Vector2()
{

}

sf::Vector2f Vector2::GetSfmlVector()
{
	return sf::Vector2f(x,y);
}

Vector2 Vector2::operator+(Vector2 v1)
{
	Vector2 V(0.0f, 0.0f);
	V.x = v1.x + x;
	V.y = v1.y + y;
	return V;
}

Vector2 Vector2::operator-(Vector2 v1)
{
	Vector2 V(0.0f, 0.0f);
	V.x = v1.x - x;
	V.y = v1.y - y;
	return V;
}

Vector2 Vector2::operator*(float m)
{
	Vector2 V(0.0f, 0.0f);
	V.x = m * x;
	V.y = m * y;
	return V;
}

float Vector2::Length()
{
	return sqrt(x*x + y*y);
}

float Vector2::Dot(Vector2 v1, Vector2 v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y);
}

Vector3 Vector2::Cross(Vector2 v1, Vector2 v2)
{
	Vector3 V(0.0f, 0.0f, 0.0f);
	V.z = (v1.x * v2.y - v1.y * v2.x);
	return V;
}

Vector2 Vector2::Lerp(Vector2 v1, Vector2 v2, float ratio)
{
	return v1 + ((v2 - v1) * ratio);
}

Vector2 Vector2::Proj(Vector2 v1, Vector2 v2)
{
	return v1 * (Vector2::Dot(v2, v1) / Vector2::Dot(v1, v2));
}

Vector2 Vector2::Refl(Vector2 inDir, Vector2 normal)
{
	return  inDir - normal * (2 * Vector2::Dot(inDir, normal));
}

float Vector2::AnglesBetween(Vector2 v1, Vector2 v2)
{
	return acos(Vector2::Dot(v1, v2) /
		(v1.Length() * v2.Length()));
}

void Vector2::Show()
{
	std::cout << "x: " << x << "y: " << y << "\n";
}

Vector2::~Vector2()
{

}
