#include "World.h"



World::World()
{

}
////////////for use in quadTree, didn't do because don't understant how to do////////////////
Rigidbody* World::addBodyWorld()
{
	Rigidbody* body = new Rigidbody();
	bodies.push_back(body);
	return body;
}

World::~World()
{
	for (auto i = bodies.begin(); i != bodies.end(); i++)
	{
		delete *i;
	}
	bodies.clear();
}
