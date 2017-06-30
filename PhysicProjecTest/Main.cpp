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
	//////////////UTILE POUR TEST AABB///////
	/*
	AABB rect1;
	AABB rect2;
	rect1.setPosition(Vector2(300.0f, 400.0f));
	rect1.SetSize(Vector2(100.0f, 100.0f));
	rect2.setPosition(Vector2(300.0f, 100.0f));
	rect2.SetSize(Vector2(200.0f, 200.0f));*/
	
	/////////UTILE POUR TEST COLLIDER////////
	RectangleCollider rect1;
	RectangleCollider rect2;
	CircleCollider circle1;
	CircleCollider circle2;
	rect1.setOffset(Vector2(300.0f, 400.0f));
	rect1.SetSize(Vector2(100.0f, 100.0f));
	circle1.setOffset(Vector2(300.0f, 100.0f));
	circle1.setRadius(50.0f);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		////////UTILE POUR TEST AABB///////
		/*
		rect1.AABB_Move();
		rect1.IsOverlapping(&rect2);
		rect2.IsOverlapping(&rect1);*/

		window.clear();

		////////UTILE POUR TEST AABB//////////////
		/*
		rect1.update(&window);
		rect2.update(&window);*/

		////////UTILE POUR TEST COLLIDER/////////
		circle1.Circle_move();
		circle1.is_colliding(&circle2);

		circle1.circleUpdate(&window);
		rect1.rectangleUpdate(&window);
		circle2.circleUpdate(&window);
		window.display();
	}
	return 0;
}

