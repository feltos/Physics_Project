#include "Rigidbody.h"
#include "Vector2.h"
#include "vector3.h"


Rigidbody::Rigidbody(float vx, float vy, float px, float py)
{
	vitesse.x = vx;
	vitesse.y = vy;
	position.x = px;
	position.y = py;
}

Vector2 Rigidbody::Addforce(Vector2 F)
{
	return F;
}

void Rigidbody::Update()
{

}


Rigidbody::~Rigidbody()
{

}
