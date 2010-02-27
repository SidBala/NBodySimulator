#include "stdafx.h"
#include "PlanetDefs.h"
/*
CPlanetSun::CPlanetSun(void)
{

	v3Pf = CVec3(10,0,0);			//	Give object an initial position
	v3Vf = CVec3(0,0,10);			//	Give object an initial velocity
	
	fMass = 100;					//	Give object a mass
	fRadius = 1;					//	Give object a radius

}
CPlanetSun::~CPlanetSun(void)
{
	//	Flush out any texture objects and animation objects

}
void CPlanetSun::DrawObject(void)
{
	//	Draw Object here

}*/


CPlanetSun::CPlanetSun(void)
{

	v3Pf = CVec3(0,0,0);			//	Give object an initial position
	v3Vf = CVec3(0,0,0);			//	Give object an initial velocity
	
	fMass = 500;					//	Give object a mass
	fRadius = 0.5;					//	Give object a radius

}
CPlanetSun::~CPlanetSun(void)
{
	//	Flush out any texture objects and animation objects

}
void CPlanetSun::DrawObject(void)
{
	printf("\nSunPos x:%f y:%f z:%f",v3Pf.x,v3Pf.y,v3Pf.z);

	//glLoadIdentity();

	glTranslatef(v3Pf.x,v3Pf.y,v3Pf.z);

	
			glBegin (GL_TRIANGLES);								// Triangle Represents a planet 
				glColor3f (1.f, 0.f, 0.f);	glVertex3f( 0.0f, 0.1f, 0.0f);
				glColor3f (0.f, 1.f, 0.f);	glVertex3f(-0.1f,-0.1f, 0.1f);
				glColor3f (0.f, 0.f, 1.f);	glVertex3f( 0.1f,-0.1f, 0.1f);
			glEnd ();
			// Done Drawing Triangles
}



//Earth
CPlanetEarth::CPlanetEarth(void)
{

	v3Pf = CVec3(0,3,0);			//	Give object an initial position
	v3Vf = CVec3(1,0,4);			//	Give object an initial velocity
	
	fMass = 1.0f;						//	Give object a mass
	fRadius = 0.1f;					//	Give object a radius

}
CPlanetEarth::~CPlanetEarth(void)
{
	//	Flush out any texture objects and animation objects

}
void CPlanetEarth::DrawObject(void)
{
		printf("\nEarthPos x:%f y:%f z:%f",v3Pf.x,v3Pf.y,v3Pf.z);

	//glLoadIdentity();

	glTranslatef(v3Pf.x,v3Pf.y,v3Pf.z);

	
			//glRotatef(180.0f,0.0f,1.0f,0.0f);					// Rotate 180 Degrees On The Y-Axis
			glBegin (GL_TRIANGLES);								// Begin Drawing Triangles
				glColor3f (1.f, 0.f, 0.f);	glVertex3f( 0.0f, 0.1f, 0.0f);
				glColor3f (0.f, 1.f, 0.f);	glVertex3f(-0.1f,-0.1f, 0.1f);
				glColor3f (0.f, 0.f, 1.f);	glVertex3f( 0.1f,-0.1f, 0.1f);
			glEnd ();



	//	Draw Object here
}

//VENUS

CPlanetVenus::CPlanetVenus(void)
{

	v3Pf = CVec3(0,5,0);			//	Give object an initial position
	v3Vf = CVec3(1.2,0,0);			//	Give object an initial velocity
	
	fMass = 0.5f;					//	Give object a mass
	fRadius = 0.05f;					//	Give object a radius

}
CPlanetVenus::~CPlanetVenus(void)
{
	//	Flush out any texture objects and animation objects

}
void CPlanetVenus::DrawObject(void)
{
		printf("\nVenusPos x:%f y:%f z:%f",v3Pf.x,v3Pf.y,v3Pf.z);
	//glLoadIdentity();
	glTranslatef(v3Pf.x,v3Pf.y,v3Pf.z);

	
			//glRotatef(180.0f,0.0f,1.0f,0.0f);					// Rotate 180 Degrees On The Y-Axis
			glBegin (GL_TRIANGLES);								// Begin Drawing Triangles
				glColor3f (1.f, 0.f, 0.f);	glVertex3f( 0.0f, 0.1f, 0.0f);
				glColor3f (0.f, 1.f, 0.f);	glVertex3f(-0.1f,-0.1f, 0.1f);
				glColor3f (0.f, 0.f, 1.f);	glVertex3f( 0.1f,-0.1f, 0.1f);
			glEnd ();



	//	Draw Object here
}