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
	rectangle.setSize(sf::Vector2f (100.0f,100.0f));
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

void AABB::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rectangle.move(0.1, 0);
		center = center + Vector2(0.1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rectangle.move(-0.1, 0);
		center = center + Vector2(-0.1, 0);
	}	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		rectangle.move(0, -0.1);
		center = center + Vector2(0, -0.1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		rectangle.move(0, 0.1);
		center = center + Vector2(0, 0.1);
	}
}

bool AABB::isColliding(AABB* aabb)
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
