#include "Rigidbody.h"
#include "Vector2.h"
#include "vector3.h"
#include "iostream"
#include <iomanip>
#include <time.h>
#include <ctime>

Rigidbody::Rigidbody(float vx, float vy, float px, float py)
{
	///////////pour le temps qui passe///////////////
	clock_t start_s = clock();

	vitesse.x = vx;
	vitesse.y = vy;
	position.x = px;
	position.y = py;
	acceleration.x = 0.0;
	acceleration.y = 0.0;
}

Vector2 Rigidbody::Direction(Vector2 P1, Vector2 P2)
{
	direction.x = P1.x - P2.x;
	direction.y = P1.y - P2.y;
	return direction;
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

void Rigidbody::Update()
{
	for (float t = 0.0f; t <= 1.0f; t += 1.0f / 60.0f)
	{
		clock_t time = clock();
		float ti = float(time)/1000.0f;

		///////////////////////MRUA//////////////////////////
		position.x += ((1.0f/2.0f) * acceleration.x) * (ti * ti) + vitesse.x * ti;
		position.y += ((1.0f/2.0f) * acceleration.y) * (ti * ti) + vitesse.y * ti;
		std::cout<< std::fixed << "x = " << position.x << " , " << "y = " << position.y << "\n";
	}
	
}


Rigidbody::~Rigidbody()
{

}
