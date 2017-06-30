#include "Collider.h"
#include <cmath>

Collider::Collider(Vector2 offset, Rigidbody* rigidbody)
{
	this->offset = offset;
}

Collider::Collider()
{

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

RectangleCollider::RectangleCollider()
{
	rectangle.setFillColor(sf::Color::Green);
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
		rectangle.setFillColor(sf::Color::Red);
		return true;
	}
	else
	{
		rectangle.setFillColor(sf::Color::Green);
		return false;
	}
}

void RectangleCollider::SetSize(Vector2 s)
{
	size = s;
	rectangle.setSize(s.GetSfmlVector());
}

void RectangleCollider::Rectangle_move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rectangle.move(0.1, 0);
		offset = offset + Vector2(0.1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rectangle.move(-0.1, 0);
		offset = offset + Vector2(-0.1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		rectangle.move(0, -0.1);
		offset = offset + Vector2(0, -0.1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		rectangle.move(0, 0.1);
		offset = offset + Vector2(0, 0.1);
	}
}

void RectangleCollider::rectangleUpdate(sf::RenderWindow*w)
{
	w->draw(rectangle);
}

RectangleCollider::~RectangleCollider()
{

}

////////////////////START CIRCLE///////////////////////

CircleCollider::CircleCollider(float radius, Vector2 offset, Rigidbody* rigidbody): Collider(offset, rigidbody)
{
	this->offset = offset;
	this->radius = radius;
	circle.setFillColor(sf::Color::Green);
}

CircleCollider::CircleCollider()
{

}

void CircleCollider::setRadius(float r)
{
	radius = r;
	circle.setRadius(r);
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
		circle.setFillColor(sf::Color::Red);
		return true;
	}
	else
	{
		circle.setFillColor(sf::Color::Green);
		return false;
	}
}

bool CircleCollider::is_colliding(RectangleCollider* col)
{
	Vector2 circleDistance;
	float cornerDistance_sq;
	circleDistance.x = abs(this->offset.x - col->offset.x);
	circleDistance.y = abs(this->offset.y - col->offset.y);

	if (circleDistance.x > (col->size.x / 2 + this->radius)) { circle.setFillColor(sf::Color::Green); return false; }
	if (circleDistance.y > (col->size.y / 2 + this->radius)) { circle.setFillColor(sf::Color::Green); return false; }

	if (circleDistance.x <= (col->size.x / 2)) { circle.setFillColor(sf::Color::Red); return true; }
	if (circleDistance.y <= (col->size.y / 2)) { circle.setFillColor(sf::Color::Red); return true; }

	cornerDistance_sq = pow((circleDistance.x - col->size.x / 2.0f), 2.0f) +
		pow((circleDistance.y - col->size.y / 2.0f), 2.0f);

	return (cornerDistance_sq <= pow(this->radius, 2.0f));
}

void CircleCollider::Circle_move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		circle.move(0.1, 0);
		offset = offset + Vector2(0.1, 0);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		circle.move(-0.1, 0);
		offset = offset + Vector2(-0.1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		circle.move(0, -0.1);
		offset = offset + Vector2(0, -0.1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		circle.move(0, 0.1);
		offset = offset + Vector2(0, 0.1);
	}
}

void CircleCollider::circleUpdate(sf::RenderWindow* w)
{
	w->draw(circle);
}

CircleCollider::~CircleCollider()
{

}

