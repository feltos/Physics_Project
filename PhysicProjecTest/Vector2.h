
#ifndef VECTOR2_H
#define VECTOR2_H
#include "Vector3.h"

class Vector2
{
public:
	Vector2(float x, float y);
	Vector2();
	float x;
	float y;
	float Length();

	Vector2 operator+(Vector2 v1);
	Vector2 operator-(Vector2 v1);
	Vector2 operator*(float m);
	static float Dot(Vector2 v1, Vector2 v2);
	static Vector3 Cross(Vector2 v1, Vector2 v2);
	static Vector2 Lerp(Vector2 v1, Vector2 v2, float ratio);
	static Vector2 Proj(Vector2 v1, Vector2 v2);
	static Vector2 Refl(Vector2 inDir, Vector2 normal);
	static float AnglesBetween(Vector2 v1, Vector2 v2);
	void Show();

	~Vector2();

};

#endif // !VECTOR2_H
