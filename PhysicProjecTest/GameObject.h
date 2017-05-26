#ifndef GameObject
#define GAMEOBJECT_H

#include "Collider.h"
#include "AABB.h"
#include "Rigidbody.h"

class GameObject
{
private:
	Vector2 Size;
	Vector2 position;
	sf::RectangleShape rect;
public:
	GameObject(Vector2 size,Vector2 position);

	Rigidbody* rigidbody;
	AABB aabb;
	Collider* collider;
	
	void SetPos(Vector2 position);
	void draw(sf::RenderWindow&);
	~GameObject();
};
#endif // !GameObject

