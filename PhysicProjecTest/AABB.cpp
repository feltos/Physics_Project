#include "AABB.h"
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <iostream>
AABB::AABB(Vector2 c, Vector2 s)
{
	center = c;
	size = s;
}

AABB::AABB()
{
	center = Vector2(0.0f, 0.0f);
	size = Vector2(0.0f, 0.0f);
	rectangle.setSize(sf::Vector2f (0.0f,0.0f));
	rectangle.setFillColor(sf::Color::Green);
}

void AABB::SetCenter(Vector2 c)
{
	center = c;
	rectangle.setPosition(c.GetSfmlVector());
}

void AABB::SetSize(Vector2 s)
{
	size = s;
	rectangle.setSize(s.GetSfmlVector());
}

bool AABB::IsOverlapping(AABB* aabb)
{
	if ((this->center.x + this->size.x) < aabb->center.x || this->center.x > (aabb->center.x + aabb->size.x))
	{
		return false;
	}
	if ((this->center.y + this->size.y) < aabb->center.y || (aabb->center.y + aabb->size.y) < this->center.y)
	{
		return false;
	}
	else
	{
		return true;
	}
	
}

void AABB::update(sf::RenderWindow* w)
{	
	w->draw(rectangle);	
}

AABB::~AABB()
{

}
