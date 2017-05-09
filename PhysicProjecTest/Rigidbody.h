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

	Rigidbody(float vx, float vy,float px, float py);	
	Vector2 Addforce(Vector2 forceF);
	void Update();

	~Rigidbody();

#endif // !Rigidbody
};

