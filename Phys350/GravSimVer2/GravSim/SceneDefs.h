#pragma once

#include "Scene.h"

//	This file contains all the descriptions of the scenes
//	Inherit all scenes from CScene
//	Only the constructor needs to be defined
//	The constructor needs to loadup the nodelist with all
//	the objects that we want to see in the scene

class DefaultScene: public CScene
{
public:
	DefaultScene()
	{
		SceneName = "Default Scene";			//	Specify the scenename
												
												//	Build the scene component wise

		AddNode(new CGravObject("Earth",CVec3(0,0,0),CVec3(0,0,0),500,0.5,2,-4,"tim102","earthclouds"));
		AddNode(new CGravObject("Moon",CVec3(0,0,3),CVec3(4,0,0),100,0.2,2,-4,"nr2-bump","SamothraceClouds"));
		AddNode(new CGravObject("Moon2",CVec3(0,0,-3),CVec3(-4,0,0),100,0.1,2,"nr2"));

		/*AddNode(new CPlanetEarth);
		AddNode(new CPlanetSun);
		AddNode(new CPlanetNemesis);
		AddNode(new CPlanetMoon);
		AddNode(new CPlanetVenus);
		AddNode(new CGravObject(CVec3(0,0,-5),CVec3(0,3,0),5,0.08));*/
	}
};

class WhateverScene: public CScene
{
public:
	WhateverScene()
	{
		SceneName = "Whatever Scene";			//	Specify the scenename
												
												//	Build the scene component wise
	/*	AddNode(new CGravObject(CVec3(0,0,-5),CVec3(0,3,0),500,0.08));
		AddNode(new CGravObject(CVec3(0,0,+5),CVec3(0,3,0),500,0.08));
		AddNode(new CGravObject(CVec3(0,-5,0),CVec3(0,0,-3),1000,0.08));
		AddNode(new CGravObject(CVec3(0,+5,0),CVec3(0,0,-3),500,0.08));*/

		
	}
};