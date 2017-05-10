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
	Rigidbody rond1(-1.0f, 0.0f, 5.0f, 0.0f);
	Rigidbody rond2(2.0f, 0.0f, -5.0f, 0.0f);
	rond2.force = Vector2(1, 2);

	for (float t = 0.0f; t < 1.0f; t += 1.0f / 60.0f)
	{
		rond2.Update();
	}
	
	system("pause");
    return 0;
}
