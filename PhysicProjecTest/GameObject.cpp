#include "GameObject.h"



GameObject::GameObject(Shapetype shapetype)
{
	rigidbody = new Rigidbody;
	collider = new Collider(rigidbody, Vector2(0.0f, 0.0f));
	aabb = AABB(Vector2(0.0f, 0.0f), Vector2(0.0f, 0.0f));
}


GameObject::~GameObject()
{

}
