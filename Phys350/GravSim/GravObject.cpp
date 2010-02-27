#include "stdafx.h"
#include "GravObject.h"
#include <math.h>

CVec3::CVec3(void)
{
	x=y=z=0;										//	Initialize to 0
}

CVec3::CVec3 (const CVec3 & temp)
{
	x = temp.x;
	y = temp.y;
	z = temp.z;
}

CVec3::CVec3(float nx,float ny,float nz)
{
	x = nx;											//	Constructor with individual float values
	y = ny;
	z = nz;
}

CVec3::~CVec3(void)									//	Nothing to do here. No dynamic memory
{
}

float CVec3::Norm()									//	Returns the 2-Norm of the vector
{
	return (float) sqrt(x*x + y*y + z*z);
}

float CVec3::NormSq()
{
	return (float)(x*x + y*y + z*z);
}

CVec3 & CVec3::operator=(const CVec3 &v)						// Assignment Operator
{
	if (this != &v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}
	return *this;
}



CVec3 operator+(const CVec3 &v1, const CVec3 &v2)
{
	
	float x,y,z;
	x = v1.x + v2.x;
	y = v1.y + v2.y;
	z = v1.z + v2.z;
	return CVec3 (x,y,z);
}

CVec3 operator-(const CVec3 &v1, const CVec3 &v2)
{
	float x,y,z;
	x = v1.x - v2.x;
	y = v1.y - v2.y;
	z = v1.z - v2.z;
	return CVec3 (x,y,z);
}

CVec3 operator*(const CVec3 &v, const float f)
{
	float x,y,z;
	x = v.x * f;
	y = v.y * f;
	z = v.z * f;
	return CVec3 (x,y,z);
}

CVec3 operator*(const float f, const CVec3 &v)
{
	float x,y,z;
	x = v.x * f;
	y = v.y * f;
	z = v.z * f;
	return CVec3 (x,y,z);
}

CVec3 operator/(const CVec3 &v, const float f)
{
	float x,y,z;
	x = v.x / f;
	y = v.y / f;
	z = v.z / f;
	return CVec3 (x,y,z);
}


CGravObject::CGravObject(void)
{
}

CGravObject::~CGravObject(void)
{
}

void CGravObject::DrawObject(void)
{
	printf("\n BaseClass DrawObject");

}