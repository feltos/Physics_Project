#include "Vector2.h"
#include "vector3.h"
#include "AABB.h"
#include "World.h"
#ifndef RIGIDBODY_H

class Rigidbody
{
	
private:
	Vector2 force;
	Vector2 delta;
	Vector2 acceleration;
	Vector2 position;
	Vector2 vitesse;
	Vector2 size;
	float mass;
	bool collide = false;

public:
	Rigidbody(float vx, float vy,float px, float py);	
	Vector2 Addforce(Vector2 acceleration);
	Vector2 SetAcceleration();
	Vector2 Delta(Vector2 position1, Vector2 position2);
	Vector2 GetPosition();
	void Update();
	void SetMass(float newMass);
	

	~Rigidbody();

#endif // !RIGIDBODY_H
};

