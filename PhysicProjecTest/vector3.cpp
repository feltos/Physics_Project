#include "Vector3.h"
#include "iostream"
#include "numeric"

Vector3::Vector3(float vx, float vy, float vz)
{
	x = vx;
	y = vy;
	z = vz;
}

Vector3 Vector3::operator+(Vector3 v1)
{
	Vector3 V(0.0f, 0.0f, 0.0f);
	V.x = v1.x + x;
	V.y = v1.y + y;
	V.z = v1.z + z;
	return V;
}

Vector3 Vector3::operator-(Vector3 v1)
{
	Vector3 V(0.0f, 0.0f, 0.0f);
	V.x = v1.x - x;
	V.y = v1.y - y;
	V.z = v1.z - z;
	return V;
}

Vector3 Vector3::operator*(float m)
{
	Vector3 V(0.0f, 0.0f, 0.0f);
	V.x = m * x;
	V.y = m * y;
	V.z = m * z;
	return V;
}

float Vector3::Length()
{
	return sqrt(x*x + y*y + z*z);
}

float Vector3::Dot(Vector3 v1, Vector3 v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

Vector3 Vector3::Cross(Vector3 v1, Vector3 v2)
{
	return Vector3(v1.y*v2.z - v1.z * v2.y,
		v1.z*v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x);
}

Vector3 Vector3::Lerp(Vector3 v1, Vector3 v2, float ratio)
{
	return v1 + ((v2 - v1) * ratio);
}

Vector3 Vector3::Proj(Vector3 v1, Vector3 v2)
{
	return v1 * (Vector3::Dot(v2, v1) / Vector3::Dot(v1, v2));
}

Vector3 Vector3::Refl(Vector3 inDir, Vector3 normal)
{
	return  inDir - normal * (2 * Vector3::Dot(inDir, normal));
}

float Vector3::AnglesBetween(Vector3 v1, Vector3 v2)
{
	////Trouvé chez philippe car pas compris et demanderais demain/////
	return acos(Vector3::Dot(v1, v2) /
		(v1.Length() * v2.Length()));
}

void Vector3::Show()
{
	std::cout << "x: " << x << "y: " << y << "z: " << z << "\n";
}

Vector3::~Vector3()
{

}