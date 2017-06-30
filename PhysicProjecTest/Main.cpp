// PhysicProjecTest.cpp : définit le point d'entrée pour l'application console.
//

#include "iostream"
#include "Vector2.h"
#include "World.h"
#include <SFML\Graphics.hpp>
#include "GameObject.h"



int main()
{
	sf::RenderWindow window(sf::VideoMode(1000,800), "TEST");
	AABB rect1;
	AABB rect2;
	rect1.setPosition(Vector2(300.0f, 400.0f));
	rect1.SetSize(Vector2(100.0f, 100.0f));
	rect2.setPosition(Vector2(300.0f, 100.0f));
	rect2.SetSize(Vector2(200.0f, 200.0f));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
			
		rect1.AABB_Move();
		rect1.IsOverlapping(&rect2);
		rect2.IsOverlapping(&rect1);
		window.clear();
		rect1.update(&window);
		rect2.update(&window);
		window.display();
	}
	return 0;
}

