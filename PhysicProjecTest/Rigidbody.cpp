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

Vector2 Rigidbody::Direction(Vector2 P1, Vector2 P2)
{
	direction.x = P1.x - P2.x;
	direction.y = P1.y - P2.y;
	return direction;
}

Vector2 Rigidbody::Addforce(Vector2 F)
{
	F.x = mass * acceleration.x;
	F.y = mass * acceleration.y;
	return F;
}

Vector2 Rigidbody::AddAcceleration(Vector2 A)
{
	A.x = force.x / mass;
	A.y = force.y / mass;
	return A;
}

void Rigidbody::Update()
{
	///////////pour le temps qui passe///////////////
	clock_t start_s = clock();
	///////////////////////MRUA//////////////////////////
	position.x += ((1 / 2)* acceleration.x) + vitesse.x;
	position.y += ((1 / 2)* acceleration.y) * (clock() * clock()) + vitesse.y * clock();
	std::cout << "x = " << position.x << " , " << "y = " << position.y << "\n";
}


Rigidbody::~Rigidbody()
{

}
