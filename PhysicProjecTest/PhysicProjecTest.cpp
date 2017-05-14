// PhysicProjecTest.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "iostream"
#include "Rigidbody.h"
#include "Vector2.h"
#include "vector3.h"
#include <time.h>
#include <ctime>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");

	///////////création des rigidbody/////////
	Rigidbody square(0.0f, 0.0f, 0.0f, 0.0f);

	///////////ajout / modif des attributs ///////////////
	square.Addforce(Vector2(0.1f, 0.0f));
	square.SetMass(1.0f);
	square.Update();
	
	sf::CircleShape shape(50.f);
	shape.setOrigin(-200.0f,-200.0f);
	shape.setFillColor(sf::Color::Green);
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	system("pause");
    return 0;
}

