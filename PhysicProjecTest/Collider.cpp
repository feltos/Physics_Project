#include "Collider.h"
#include <cmath>

Collider::Collider(Vector2 offset, Rigidbody* rigidbody)
{
	this->offset = offset;
}

void Collider::setOffset(Vector2 newOffset)
{
	offset = newOffset;
}

Collider::~Collider()
{

}
//////////////////START RECTANGLE//////////////////////
RectangleCollider::RectangleCollider(Vector2 size, Vector2 offset, Rigidbody* rigidbody) :Collider(offset, rigidbody)
{
	this->size = size;
}

bool RectangleCollider::is_colliding(Collider* col)
{
	RectangleCollider* r = dynamic_cast <RectangleCollider*> (col);
	if (r != NULL)
	{
		return is_colliding(r);
	}

	CircleCollider* c = dynamic_cast <CircleCollider*> (col);
	if (c != NULL)
	{
		return is_colliding(c);
	}
}
////////////////same as CircleCollider::is_colliding(RectangleCollider*)///////////
bool RectangleCollider::is_colliding(CircleCollider* col)
{
	return col->is_colliding(this);
}

bool RectangleCollider::is_colliding(RectangleCollider* col)
{
	if (this->offset.x < col->offset.x + col->size.x &&
		this->offset.x + this->size.x > col->offset.x &&
		this->offset.y < col->offset.y + col->size.y &&
		this->size.y + this->offset.y > col->offset.y)
	{		
		return true;
	}
	else
	{
		return false;
	}
}

RectangleCollider::~RectangleCollider()
{

}

////////////////////START CIRCLE///////////////////////

CircleCollider::CircleCollider(float radius, Vector2 offset, Rigidbody* rigidbody): Collider(offset, rigidbody)
{
	this->offset = offset;
	this->radius = radius;
}

bool CircleCollider::is_colliding(Collider* col)
{
	RectangleCollider* r = dynamic_cast <RectangleCollider*> (col);
	if (r != NULL)
	{
		return is_colliding(r);
	}

	CircleCollider* c = dynamic_cast <CircleCollider*> (col);
	if (c != NULL)
	{
		return is_colliding(c);
	}
}

bool CircleCollider::is_colliding(CircleCollider* col)
{
	double dx = this->offset.x - col->offset.x;
	double dy = this->offset.y - col->offset.y;
	double distance = sqrt(dx*dx + dy*dy);
	if (distance < this->radius + col->radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CircleCollider::is_colliding(RectangleCollider* col)
{
	Vector2 circleDistance;
	float cornerDistance_sq;
	circleDistance.x = abs(this->offset.x - col->offset.x);
	circleDistance.y = abs(this->offset.y - col->offset.y);

	if (circleDistance.x > (col->size.x / 2 + this->radius)) { return false; }
	if (circleDistance.y > (col->size.y / 2 + this->radius)) { return false; }

	if (circleDistance.x <= (col->size.x / 2)) { return true; }
	if (circleDistance.y <= (col->size.y / 2)) { return true; }

	cornerDistance_sq = pow((circleDistance.x - col->size.x / 2.0f), 2.0f) +
		pow((circleDistance.y - col->size.y / 2.0f), 2.0f);

	return (cornerDistance_sq <= pow(this->radius, 2.0f));
}

CircleCollider::~CircleCollider()
{

}

