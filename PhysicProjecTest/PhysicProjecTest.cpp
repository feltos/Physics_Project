// PhysicProjecTest.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "iostream"
#include "Rigidbody.h"
#include "Vector2.h"
#include "vector3.h"

int main()
{
	Rigidbody rond1(1.0f, 1.0f, 5.0f, 5.0f);

	Vector2 A (8, 1);
	Vector3 B(1, 1, 0);
	std::cout << rond1.position.x << rond1.vitesse.x << "\n";
	system("pause");
    return 0;
}

