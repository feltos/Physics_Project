#include "Vector2.h"
#include "vector3.h"
#ifndef RIGIDBODY_H

class Rigidbody
{

private:
	Vector2 force;
	Vector2 direction;
	Vector2 acceleration;
	Vector2 position;
	Vector2 vitesse;
	float mass;

public:
	Rigidbody(float vx, float vy,float px, float py);	
	Vector2 Addforce(Vector2 acceleration);
	Vector2 SetAcceleration();
	Vector2 Direction(Vector2 position1, Vector2 position2);
	Vector2 GetPosition();
	void Update();
	void SetMass(float newMass);
	

	~Rigidbody();

#endif // !RIGIDBODY_H
};

