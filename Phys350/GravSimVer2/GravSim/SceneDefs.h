#pragma once

#include "Scene.h"

//	This file contains all the descriptions of the scenes
//	Inherit all scenes from CScene
//	Only the Init() needs to be defined
//	The Init() needs to loadup the nodelist with all
//	the objects that we want to see in the scene

//	Dont forget to add these scenes to the scene manager

class SolarSystem: public CScene
{
public: 
	void Init()
	{
		SceneName = "SolarSystem";			//	Specify the scenename
												
		NodeList.clear();

		fSpeed = 0.01;
												//	Build the scene component wise

/*		AddNode(new CGravObject("Earth",CVec3(0,0,0),CVec3(0,0,0),500,0.5,1,-2,"tim102","MarsClouds",100));
		AddNode(new CGravObject("Moon",CVec3(0,0,3),CVec3(4,0,0),100,0.2,2,-4,"nr2-bump","SamothraceClouds",100));
		AddNode(new CGravObject("Moon2",CVec3(0,0,-3),CVec3(-4,0,0),100,0.1,2,"nr2",100));
*/
		AddNode(new CGravObject("Sun",CVec3(0,0,0),CVec3(0,0,0),5000,0.5,2,-4,"th_sun","th_suncover",100));
		AddNode(new CGravObject("Mercury",CVec3(2,0,0),CVec3(0,15,0),1,0.026*3,2,-4,"nr2-bump","SamothraceClouds",68));
		AddNode(new CGravObject("Venus",CVec3(-3,0,0),CVec3(0,-13.5,0),4,0.00065*3,2,-4,"nr2-bump","SamothraceClouds",165));
		AddNode(new CGravObject("Earth",CVec3(0,-4.5,0),CVec3(11,0,0),5,0.00137*3,2,-4,"nr2-bump","SamothraceClouds",300));
		AddNode(new CGravObject("Mars",CVec3(0,6,0),CVec3(-9,0,0),2,0.00073*3,2,-4,"nr2-bump","SamothraceClouds",380));
		AddNode(new CGravObject("Jupiter",CVec3(11,0,0),CVec3(0,7,0),30,0.015*3,2,-4,"nr2-bump","SamothraceClouds",1150));
		//AddNode(new CGravObject("Saturn",CVec3(-,0,0),CVec3(-11.53,0,0),12,0.013*3,100));
	/*	AddNode(new CGravObject("Uranus",CVec3(0,19.7,0),CVec3(27.2,0,0),21.82,0.0055*3,100));
		AddNode(new CGravObject("Neptune",CVec3(0,30.56,0),CVec3(-28,0,0),25.75,0.0053*3,100));
		AddNode(new CGravObject("Pluto",CVec3(0,40,0),CVec3(611,0,0),0.003,0.00024*3,100));	
	*/





	}
};

class WhateverScene: public CScene
{
public:
	void Init()
	{
		NodeList.clear();
		
		SceneName = "Whatever Scene";						//	Specify the scenename

		fSpeed = 0.001;
		
		AddNode(new CGravObject("Blearth",CVec3(0,0,0),CVec3(0,0,0),1500,0.5,2,-1,"tim102","earthclouds",20));
		AddNode(new CGravObject("Noom",CVec3(0,1.5,0),CVec3(0,0,6),100,0.2,2,-4,"nr2-bump","SamothraceClouds",40));
		AddNode(new CGravObject("RockMoon",CVec3(0,-1.5,0),CVec3(0,0,-6),100,0.1,2,"nr2",100));
												
												//	Build the scene component wise
	}
};

class BlackHole: public CScene
{
public:
	void Init()
	{
		NodeList.clear();
		SceneName = "BlackHole";						//	Specify the scenename

		fSpeed = 0.001;
		
		
		AddNode(new CGravObject("Blearth",CVec3(0,0,0),CVec3(0,0,0),700,0.5,2,-4,"tim102","earthclouds",100));
		AddNode(new CGravObject("Noom",CVec3(0,1.5,0),CVec3(0,0,6),100,0.2,2,-4,"nr2-bump","SamothraceClouds",100));
		AddNode(new CGravObject("RockMoon",CVec3(0,-1.5,0),CVec3(0,0,-6),100,0.1,2,"nr2",100));

		AddNode(new CGravObject("BlackHole",CVec3(0,-25,1),CVec3(0,15,0),1000,0.1,2,"nr2",100));


												
												//	Build the scene component wise
	}
};