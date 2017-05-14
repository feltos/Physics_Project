#pragma once
#include "Rigidbody.h"
#include "Vector2.h"
#include "vector3.h"
#include <list>
class World
{
public:
	World();
//	_LIST_ Rigidbody;
		
	~World();

private:
	///////bord du monde, de l'écran//////
	float maxX;
	float minX;
	float maxY;
	float minY;
};

