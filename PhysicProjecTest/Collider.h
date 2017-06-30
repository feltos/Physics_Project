#ifndef Collider
#define COLLIDER_H

#include "Vector2.h"
#include "Rigidbody.h"

////////////this class is the parent of other class/////////
class Collider
{
protected:
	Vector2 offset;
	Rigidbody* rigidbody;
	friend class CircleCollider;
	friend class RectangleCollider;

public:
	virtual bool is_colliding(Collider*) = 0;
	Collider(Vector2 offset, Rigidbody* rigidbody);
	Collider();
	sf::Shape* shape;
	void setOffset(Vector2 offset);
	~Collider();
};

class CircleCollider;

class RectangleCollider : public Collider
{
private:
	Vector2 size;
	friend class CircleCollider;
public:
	RectangleCollider(Vector2 size,Vector2 offset,Rigidbody* rigidbody);
	RectangleCollider();
	bool is_colliding(Collider*);
	bool is_colliding(CircleCollider*);
	bool is_colliding(RectangleCollider*);
	sf::RectangleShape rectangle;
	void Rectangle_move();
	void rectangleUpdate(sf::RenderWindow* w);
	void SetSize(Vector2 s);
	~RectangleCollider();
};

class CircleCollider : public Collider
{
private:
	float radius;
public:
	CircleCollider(float radius,Vector2 offset,Rigidbody* rigidbody);
	CircleCollider();
	~CircleCollider();
	bool is_colliding(Collider*);
	bool is_colliding(CircleCollider*);
	bool is_colliding(RectangleCollider*);
	sf::CircleShape circle;
	void circleUpdate(sf::RenderWindow* w);
	void setRadius(float r);
	void Circle_move();
};


#endif // !Collider

