#include "Rigidbody.h"
#include "Vector2.h"
#include "vector3.h"
#include "iostream"
#include <time.h>
#include <ctime>

Rigidbody::Rigidbody(float vx, float vy, float px, float py)
{
	vitesse.x = vx;
	vitesse.y = vy;
	position.x = px;
	position.y = py;
}

Vector2 Rigidbody::AddAcceleration(Vector2 A)
{
	A.x = force.x / mass;
	A.y = force.y / mass;
	return A;
}

Vector2 Rigidbody::Addforce(Vector2 F)
{
	F.x = mass * acceleration.x;
	F.y = mass * acceleration.y;
	return F;
}

void Rigidbody::Update()
{
	position.x += vitesse.x * acceleration.x;
	position.y += vitesse.y * acceleration.y;
	std::cout << "x = " << position.x << " , " << "y = " << position.y << "\n";
}


Rigidbody::~Rigidbody()
{

}
