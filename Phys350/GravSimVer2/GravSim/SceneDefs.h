#pragma once

#include "Scene.h"

//	This file contains all the descriptions of the scenes
//	Inherit all scenes from CScene
//	Only the Init() needs to be defined
//	The Init() needs to loadup the nodelist with all
//	the objects that we want to see in the scene

//	Dont forget to add these scenes to the scene manager

class DefaultScene: public CScene
{
public:
	void Init()
	{
		SceneName = "Default Scene";			//	Specify the scenename
												
		NodeList.clear();

		fSpeed = 0.1;
												//	Build the scene component wise

		AddNode(new CGravObject("Earth",CVec3(0,0,0),CVec3(0,0,0),500,0.5,1,-2,"tim102","MarsClouds",100));
		AddNode(new CGravObject("Moon",CVec3(0,0,3),CVec3(4,0,0),100,0.2,2,-4,"nr2-bump","SamothraceClouds",100));
		AddNode(new CGravObject("Moon2",CVec3(0,0,-3),CVec3(-4,0,0),100,0.1,2,"nr2",100));

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