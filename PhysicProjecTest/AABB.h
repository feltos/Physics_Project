#pragma once
#include <SFML/Graphics.hpp>
#include "Rigidbody.h"
#include "Vector2.h"
#include "vector3.h"
#include <list>
#include "World.h"
class AABB
{
public:
	AABB();

	void GenerateCollisions(_LIST_ Rigidbody);

	~AABB();

private:
	
};

