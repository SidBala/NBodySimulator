#include "stdafx.h"
#include "PlanetDefs.h"
//CPlanetSun::CPlanetSun(void)
//{
//
//	v3Pf = CVec3(0,0,0);			//	Give object an initial position
//	v3Vf = CVec3(0,0,0);			//	Give object an initial velocity
//	
//	fMass = 500;					//	Give object a mass
//	fRadius = 0.2;					//	Give object a radius
//
//}
//CPlanetSun::~CPlanetSun(void)
//{
//	//	Flush out any texture objects and animation objects
//
//}
//void CPlanetSun::DrawObject(void)
//{
//	//printf("\nSunPos x:%f y:%f z:%f",v3Pf.x,v3Pf.y,v3Pf.z);
//
//	//glLoadIdentity();
//
//	glTranslatef(v3Pf.x,v3Pf.y,v3Pf.z);
//
//	
//			glBegin (GL_TRIANGLES);								// Triangle Represents a planet 
//				glColor3f (1.f, 0.f, 0.f);	glVertex3f( 0.0f, 0.1f, 0.0f);
//				glColor3f (0.f, 1.f, 0.f);	glVertex3f(-0.1f,-0.1f, 0.1f);
//				glColor3f (0.f, 0.f, 1.f);	glVertex3f( 0.1f,-0.1f, 0.1f);
//			glEnd ();
//			// Done Drawing Triangles
//}



CPlanetSun::CPlanetSun(void)
{

	v3Pf = CVec3(0,0.5,0);			//	Give object an initial position
	v3Vf = CVec3(-4,0,0);			//	Give object an initial velocity
	
	fMass = 500;					//	Give object a mass
	fRadius = 0.15;					//	Give object a radius

}
CPlanetSun::~CPlanetSun(void)
{
	//	Flush out any texture objects and animation objects

}
void CPlanetSun::DrawObject(void)
{
	//printf("\nSunPos x:%f y:%f z:%f",v3Pf.x,v3Pf.y,v3Pf.z);

	CGravObject::DrawObject();		//	Default Drawer


}

CPlanetNemesis::CPlanetNemesis(void)
{

	v3Pf = CVec3(0,-0.5,0);			//	Give object an initial position
	v3Vf = CVec3(4,0,0);			//	Give object an initial velocity
	
	fMass = 500;					//	Give object a mass
	fRadius = 0.1;					//	Give object a radius

}
//Suns Binary Star
CPlanetNemesis::~CPlanetNemesis(void)
{
	//	Flush out any texture objects and animation objects

}
void CPlanetNemesis::DrawObject(void)
{
	//printf("\nSunPos x:%f y:%f z:%f",v3Pf.x,v3Pf.y,v3Pf.z);

	CGravObject::DrawObject();		//	Default Drawer


}


//Earth
CPlanetEarth::CPlanetEarth(void)
{

	v3Pf = CVec3(5,0,0);			//	Give object an initial position
	v3Vf = CVec3(0,0,4);			//	Give object an initial velocity
	
	fMass = 10.0f;						//	Give object a mass
	fRadius = 0.051f;					//	Give object a radius

}
CPlanetEarth::~CPlanetEarth(void)
{
	//	Flush out any texture objects and animation objects

}
void CPlanetEarth::DrawObject(void)
{
		//printf("\nEarthPos x:%f y:%f z:%f",v3Pf.x,v3Pf.y,v3Pf.z);

	CGravObject::DrawObject();		//	Default Drawer
}


CPlanetMoon::CPlanetMoon(void)
{

	v3Pf = CVec3(5.2,0,0);			//	Give object an initial position
	v3Vf = CVec3(0,0,2);			//	Give object an initial velocity
	
	fMass = 0.1f;						//	Give object a mass
	fRadius = 0.01f;					//	Give object a radius

}
CPlanetMoon::~CPlanetMoon(void)
{
	//	Flush out any texture objects and animation objects

}
void CPlanetMoon::DrawObject(void)
{
		//printf("\nEarthPos x:%f y:%f z:%f",v3Pf.x,v3Pf.y,v3Pf.z);

	CGravObject::DrawObject();		//	Default Drawer
}

//VENUS

CPlanetVenus::CPlanetVenus(void)
{

	v3Pf = CVec3(3,0,0);			//	Give object an initial position
	v3Vf = CVec3(0,0,4);			//	Give object an initial velocity
	
	fMass = 0.5f;					//	Give object a mass
	fRadius = 0.05f;					//	Give object a radius

}
CPlanetVenus::~CPlanetVenus(void)
{
	//	Flush out any texture objects and animation objects

}
void CPlanetVenus::DrawObject(void)
{
		//printf("\nVenusPos x:%f y:%f z:%f",v3Pf.x,v3Pf.y,v3Pf.z);
	CGravObject::DrawObject();		//	Default Drawer
}