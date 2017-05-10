// PhysicProjecTest.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include "iostream"
#include "Rigidbody.h"
#include "Vector2.h"
#include "vector3.h"
#include <time.h>
#include <ctime>

int main()
{
	///////////cr�ation des rigidbody/////////
	Rigidbody rond1(-1.0f, 0.0f, 5.0f, 0.0f);
	Rigidbody rond2(2.0f, 0.0f, -5.0f, 0.0f);
	///////////ajout / modif des attributs ///////////////
	rond2.force = Vector2(0.0f, 0.0f);
	rond2.mass = 1;
	rond2.acceleration = Vector2(0.0f, 0.0f);
	///////////ex�cution//////////////
	for (float t = 0.0f; t < 1.0f; t += 1.0f / 60.0f)
	{
		rond2.Update();
	}
	std::cout << clock() << "\n";
	system("pause");
    return 0;
}

