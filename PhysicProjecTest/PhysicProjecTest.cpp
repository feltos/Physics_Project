// PhysicProjecTest.cpp : définit le point d'entrée pour l'application console.
//

#include "iostream"
#include "Vector2.h"
#include "vector3.h"
#include <time.h>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "World.h"

int main()
{
	World w;

	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
	Vector2 a(5.0f, 5.0f);
	///////////création des rigidbody/////////
	Rigidbody* body = w.addBodyWorld();
	body->SetPos(a);
	///////////ajout / modif des attributs ///////////////
	/*body.Addforce(Vector2(0.1f, 0.0f));
	body.SetMass(1.0f);
	body.Update();*/
	
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

