// PhysicProjecTest.cpp : définit le point d'entrée pour l'application console.
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
	///////////création des rigidbody/////////
	Rigidbody rond(1.0f, 0.0f, 0.0f, 0.0f);
	///////////ajout / modif des attributs ///////////////
	rond.Addforce(Vector2(10.0f, 0.0f));
	rond.SetMass(1.0f);
	
	
	rond.Update();
	
	
	system("pause");
    return 0;
}

