#ifndef WORLD_H
#define WORLD_H
#include <list>
#include "Rigidbody.h"

class World
{

private:

	std::list <Rigidbody*> bodies;

public:

	World();
	Rigidbody* addBodyWorld();
	~World();
};

#endif // !World

