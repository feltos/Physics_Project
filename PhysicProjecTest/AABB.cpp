#include "AABB.h"

AABB::AABB(Vector2 c, Vector2 s)
{

}

AABB::AABB()
{

}

bool AABB::isColliding(AABB* r)
{
	if (this->size.x < r->size.x + r->size.x &&
		this->size.x + this->size.x > r->size.x &&
		this->size.y < r->size.y + r->size.y &&
		this->size.y + this->size.y > r->size.y)
		{
		return true;
		}
	else
		{
		return false;
		}
}

void AABB::update()
{
	
}

AABB::~AABB()
{

}
