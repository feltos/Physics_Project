// PhysicProjecTest.cpp : définit le point d'entrée pour l'application console.
//

#include "iostream"
#include "Vector2.h"
#include "World.h"
#include <SFML\Graphics.hpp>
#include "GameObject.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1000,800), "SFML works!");
	GameObject rect1(Vector2(500.0f, 500.0f), Vector2(0.0f, 0.0f));
	rect1.SetPos(Vector2(50.0f, 40.0f));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		rect1.draw(window);
		window.display();
	}
	return 0;
}

