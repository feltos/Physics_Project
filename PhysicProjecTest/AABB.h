#ifndef AABB_H
#define AABB_H

#include <SFML/Graphics.hpp>
#include "Rigidbody.h"
#include "Vector2.h"
#include "vector3.h"
#include <list>
#include "World.h"

struct AABB
{
	AABB(Vector2 c, Vector2 s);
	Vector2 center;
	Vector2 size;

	void GenerateCollisions();

	~AABB();
}; 

#endif // !AABB

