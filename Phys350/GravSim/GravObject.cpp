#include "stdafx.h"
#include "GravObject.h"
#include <math.h>

CVec3::CVec3(void)
{
	x=y=z=0;										//	Initialize to 0
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
	//Nabil and Rudy: Insert Code Here
	return 0;
	
}

CVec3 CVec3::operator=(CVec3 v)						// Assignment Operator
{
	//Nabil and Rudy: Insert Code Here
	//Make sure to check for if object v is not this

	return CVec3 (0,0,0);
}


// Nabil and Rudy: Implement the 6 friend operator functions here

CVec3 operator+(const CVec3 &v1, const CVec3 &v2)
{
	// Nabil and Rudy: use this function as a reference and implement the 5 others too.
	return CVec3(0,0,0);
}

CGravObject::CGravObject(void)
{
}

CGravObject::~CGravObject(void)
{
}

void CGravObject::DrawObject(void)
{

}