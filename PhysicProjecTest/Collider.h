#ifndef Collider
#define COLLIDER_H

#include "Vector2.h"
#include "Rigidbody.h"

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
	bool is_colliding(Collider*);
	bool is_colliding(CircleCollider*);
	bool is_colliding(RectangleCollider*);
	~RectangleCollider();
};

class CircleCollider : public Collider
{
private:
	float radius;
public:
	CircleCollider(float radius,Vector2 offset,Rigidbody* rigidbody);
	~CircleCollider();
	bool is_colliding(Collider*);
	bool is_colliding(CircleCollider*);
	bool is_colliding(RectangleCollider*);
};


#endif // !Collider

