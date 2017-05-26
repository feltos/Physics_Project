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
	
public:
	GameObject(Vector2 size,Vector2 position);
	sf::RectangleShape rect;

	Rigidbody* rigidbody;
	AABB aabb;
	Collider* collider;
	
	void SetPos(Vector2 position);
	Vector2 getPos();
	void SetColor(sf::Color color);
	void draw(sf::RenderWindow&);
	~GameObject();
};
#endif // !GameObject

