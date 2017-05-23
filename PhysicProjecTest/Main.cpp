// PhysicProjecTest.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "iostream"
#include "Vector2.h"
#include "World.h"
#include "AABB.h"
#include "Collider.h"
#include <SFML\Graphics.hpp>
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		
		window.display();
	}
	return 0;
}

