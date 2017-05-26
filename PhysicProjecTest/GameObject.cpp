#include "GameObject.h"



GameObject::GameObject(Vector2 size,Vector2 p)
{
	rigidbody = new Rigidbody;
	collider = new RectangleCollider(Vector2(50.0f,50.0f),Vector2(0.0f, 0.0f),rigidbody);
	aabb = AABB(Vector2(0.0f, 0.0f), Vector2(0.0f, 0.0f));
	position = Vector2(0.0f, 0.0f);
}

void GameObject::SetPos(Vector2 newPos)
{
	position = newPos;
	rigidbody->SetPos(position);
	collider->setOffset(position);	
}

void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(rect);
}

GameObject::~GameObject()
{
	
}
