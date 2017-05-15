#include "Rigidbody.h"
#include "Vector2.h"
#include "vector3.h"
#include "iostream"
#include <iomanip>
#include <time.h>
#include <ctime>
#include "AABB.h"
#include "World.h"

Rigidbody::Rigidbody()
{
	///////////pour le temps qui passe///////////////
	clock_t start_s = clock();

	acceleration.x = 0.0;
	acceleration.y = 0.0;
	force.x = 0.0;
	force.y = 0.0;
}

Vector2 Rigidbody::Delta(Vector2 P1, Vector2 P2)
{
	delta.x = P1.x - P2.x;
	delta.y = P1.y - P2.y;
	////////////pour AABB mais ne sait pas bien comment l'utiliser//////////////7
	float intersectX = abs(delta.x) - (this->size.x + size.x);
	float intersectY = abs(delta.y) - (this->size.y + size.y);

	return delta;
}

Vector2 Rigidbody::Addforce(Vector2 newAcceleration)
{
	force.x = mass * newAcceleration.x;
	force.y = mass * newAcceleration.y;
	
	SetAcceleration();
	return force;
}

Vector2 Rigidbody::SetAcceleration()
{
	acceleration.x = force.x / mass;
	acceleration.y = force.y / mass;

	return acceleration;
}

Vector2 Rigidbody::GetPosition()
{
	return position;
}

void Rigidbody::SetMass(float m)
{
	mass = m;	
}

void Rigidbody::SetPos(Vector2 newPos)
{
	position = newPos;
}

void Rigidbody::SetSpeed(Vector2 newSpeed)
{
	speed = newSpeed;
}

void Rigidbody::Update()
{
	for (float t = 0.0f; ; t += 1.0f / 60.0f)
	{
		clock_t time = clock();
		float ti = float(time)/1000.0f;

			///////////////////////MRUA//////////////////////////
			position.x += ((1.0f / 2.0f) * acceleration.x) * (ti * ti) + speed.x * ti;
			position.y += ((1.0f / 2.0f) * acceleration.y) * (ti * ti) + speed.y * ti;
			std::cout << std::fixed << "x = " << position.x << " , " << "y = " << position.y << "\n";
	}	
}


Rigidbody::~Rigidbody()
{

}
