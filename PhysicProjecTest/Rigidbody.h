#pragma once
#include "Vector2.h"
#include "vector3.h"
class Rigidbody
{
public:
#ifndef Rigidbody

	Vector2 position;
	Vector2 vitesse;
	Vector2 force;
	float mass;
	Vector2 acceleration;
	Vector2 direction;

	Rigidbody(float vx, float vy,float px, float py);	
	Vector2 Addforce(Vector2 forceF);
	Vector2 AddAcceleration(Vector2 acceleration);
	Vector2 Direction(Vector2 position1, Vector2 position2);
	void Update();

	~Rigidbody();

#endif // !Rigidbody
};

