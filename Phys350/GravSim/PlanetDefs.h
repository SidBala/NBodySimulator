#pragma once

#include "GravObject.h"

//	Use the below example to create your own objects
/*
class CPlanetSun:public CGravObject
{

public:
	CPlanetSun(void);
	~CPlanetSun(void);
	void Draw(void);
};
*/





class CPlanetSun: public CGravObject
{
public:
	CPlanetSun(void);
	~CPlanetSun(void);
	void DrawObject(void);
};

class CPlanetEarth: public CGravObject
{
public:
	CPlanetEarth(void);
	~CPlanetEarth(void);
	void DrawObject(void);
};

class CPlanetVenus: public CGravObject
{
public:
	CPlanetVenus(void);
	~CPlanetVenus(void);
	void DrawObject(void);
};
