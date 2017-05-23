#ifndef GameObject
#define GAMEOBJECT_H

#include "Collider.h"
#include "AABB.h"
#include "Rigidbody.h"

class GameObject
{
private:
	Rigidbody* rigidbody;
	AABB aabb;
	Collider* collider;

public:
	GameObject(Shapetype shape);
	enum class Shapetype {RECT, CIRCLE};
		
		

	~GameObject();
};
#endif // !GameObject

