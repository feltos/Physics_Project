#pragma once
#include <SFML/Graphics.hpp>
#include "Rigidbody.h"
#include "Vector2.h"
#include "vector3.h"
class Collider
{
public:
	Collider(Rigidbody);
	~Collider();

	bool CheckCollision(Collider& other);


private:
	
};

