#include "GameObject.h"


GameObject::GameObject(Vector2 size,Vector2 p)
{
	rigidbody = new Rigidbody;
	collider = new RectangleCollider(Vector2(50.0f,50.0f),Vector2(0.0f, 0.0f),rigidbody);
	aabb = AABB(Vector2(0.0f, 0.0f), Vector2(0.0f, 0.0f));
	speed = Vector2(0.0f, 0.0f);
	/////////////////rect didn't draw//////////
	rect.setOrigin(p.GetSfmlVector());
	rect.setFillColor(sf::Color::Green);
}
////////set position of all objects in the same time///////////
void GameObject::SetPos(Vector2 newPos)
{
	position.x += newPos.x + speed.x;
	position.y += newPos.y + speed.y;
	rigidbody->SetPos(position);
	collider->setOffset(position);	
	aabb.setCenter(position);
	rect.setPosition(position.GetSfmlVector());
}

Vector2 GameObject::getPos()
{
	return position;
}

void GameObject::SetColor(sf::Color color)
{
	rect.setFillColor(color);
}

void GameObject::Setspeed(Vector2 newSpeed)
{
	speed = newSpeed;
}

void GameObject::draw(sf::RenderWindow* window)
{
	window->draw(rect);
}

GameObject::~GameObject()
{
	delete rigidbody, collider, aabb, position;
}
