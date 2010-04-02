#pragma once

#include <vector>

class CVec3
{
public:
	CVec3(void);
	CVec3(float nx,float ny,float nz);
	CVec3 (const CVec3 & temp);
	~CVec3(void);

public:
	float x;
	float y;
	float z;

public:
	float Norm();
	float NormSq();
	
	friend CVec3 operator+(const CVec3 &v1, const CVec3 &v2);
	friend CVec3 operator-(const CVec3 &v1, const CVec3 &v2);

	friend CVec3 operator*(const CVec3 &v, const float f);
	friend CVec3 operator*(const float f, const CVec3 &v);

	friend CVec3 operator/(const CVec3 &v, const float f);
	friend CVec3 operator/(const float f, const CVec3 &v);
	
	CVec3 & operator=(const CVec3 &v);
};


class CGravObject
{
public: 

	CVec3 v3Vi, v3Vf;
	CVec3 v3Pi, v3Pf;
	
	float fMass;
	float fRadius;

	std::vector<CVec3> Trails;

	GLUquadric* Quadric;

public:
	CGravObject(void);
	virtual void DrawObject(void) ;
	virtual ~CGravObject(void);
};
