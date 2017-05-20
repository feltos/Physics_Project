// PhysicProjecTest.cpp : définit le point d'entrée pour l'application console.
//

#include "iostream"
#include "Vector2.h"
#include "World.h"
#include "AABB.h"
#include <SFML\Graphics.hpp>
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	AABB rect1;
	AABB rect2;
	rect1.SetCenter(Vector2(350.0f, 1.0f));
	rect1.SetSize(Vector2(100.0f, 100.0f));
	rect2.SetCenter(Vector2(40.0f, 3.0f));
	rect2.SetSize(Vector2(200.0f, 200.0f));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		rect1.move();
		rect1.isColliding(&rect2);
		rect2.isColliding(&rect1);
		window.clear();
		rect1.update(&window);
		rect2.update(&window);
		window.display();
	}

	return 0;
}

