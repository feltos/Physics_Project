// PhysicProjecTest.cpp : définit le point d'entrée pour l'application console.
//

#include "iostream"
#include "Vector2.h"
#include "World.h"
#include <SFML\Graphics.hpp>
#include "GameObject.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	GameObject rect1(Vector2(50.0f, 50.0f), Vector2(50.0f, 50.0f)); 
	rect1.SetPos(Vector2(300.0f, 100.0f));

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

