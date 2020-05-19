#include <iostream>
using std::cout;
using std::endl;
#include <math.h>

struct Vector3D
{
	float x_,y_,z_;

	Vector3D(float x =0, float y = 0, float z = 0)
	:x_(x), y_(y), z_(z)
	{}

	Vector3D(const Vector3D & v)
	:x_(v.x_), y_(v.y_), z_(v.z_)
	{}

	float Dot(const Vector3D & v)
	{
		return x_*v.x_ + y_*v.y_ + z_*v.z_;
	}

	Vector3D & Cross(const Vector3D & v)
	{
		return * new Vector3D(
			y_*v.z_ - z_*v.y_,
			z_*v.x_ - x_*v.z_,
			x_*v.y_ - y_*v.z_
			);
	}

	Vector3D & operator-(const Vector3D & v)
	{
		return * new Vector3D(x_-v.x_, y_-v.y_, z_-v.z_);
	}

	Vector3D & operator/(float d)
	{ 
		return * new Vector3D(x_/d, y_/d, z_/d);
	}
};

Vector3D & FindNorm(Vector3D & p1, Vector3D & p2, Vector3D & p3)
{
	Vector3D v1(p2-p1);
	Vector3D v2(p3-p1);

	Vector3D v3(v1.Cross(v2));
	float lng = v3.Dot(v3);
	return * new Vector3D(lng?v3/sqrt(lng):0);
}

float FindAngle(Vector3D & v1, Vector3D & v2)
{
	float N = v1.Dot(v2);
	float L1 = sqrt(v1.Dot(v1));
	float L2 = sqrt(v2.Dot(v2));
	float D = (L1*L2);

	cout << "N :" << N << " L1 :" << L1 << " L2 :" << L2 << endl;

	float cosA = N/D;
	return acos(cosA);
}

int main()
{
	Vector3D p1(0,0,0);
	Vector3D p2(7, -7,0);
	Vector3D p3(0,5,0);
	Vector3D normale = FindNorm(p1, p2, p3);

	cout << "normale : " << endl 
		<< "(" << normale.x_ <<", " << normale.y_ << ", " << normale.z_ << ")" << endl;

	cout << "angle : " << endl
		<< FindAngle(p2-p1, p3-p1) << endl;
}