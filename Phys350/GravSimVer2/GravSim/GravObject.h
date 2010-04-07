#pragma once

#include <vector>
#include <math.h>
#include <stdlib.h>
#include "TextureLoader.h"

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
	float fRotPl;
	float fRotCl;
	float fRotvPl;
	float fRotvCl;

	int iTrailLength;


	std::vector<CVec3> Trails;

	std::string strName;

	bool HasTexture;
	bool HasCloud;

	std::string Texture;
	std::string Cloud;

public:
	CGravObject(void);
	CGravObject(std::string Name , CVec3 Pi, CVec3 Vi, float Mass, float Radius, int TrailLength);											//	No Texture Constructor
	CGravObject(std::string Name , CVec3 Pi, CVec3 Vi, float Mass, float Radius,float fRot, std::string PlanetTexture, int TrailLength);	//	Planet Texture
	CGravObject(std::string Name , CVec3 Pi, CVec3 Vi, float Mass, float Radius,float fRotp, float fRotc, std::string PlanetTexture, std::string CloudTexture, int TrailLength);	//	Planet + Cloud Texture

	virtual void DrawObject(void) ;
	virtual ~CGravObject(void);

	void renderSphere( float r, int p );
};

