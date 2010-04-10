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

		fSpeed = 0.002;
												//	Build the scene component wise

/*		AddNode(new CGravObject("Earth",CVec3(0,0,0),CVec3(0,0,0),500,0.5,1,-2,"tim102","MarsClouds",100));
		AddNode(new CGravObject("Moon",CVec3(0,0,3),CVec3(4,0,0),100,0.2,2,-4,"nr2-bump","SamothraceClouds",100));
		AddNode(new CGravObject("Moon2",CVec3(0,0,-3),CVec3(-4,0,0),100,0.1,2,"nr2",100));
*/
		AddNode(new CGravObject("Sun",CVec3(0,0,0),CVec3(0,0,0),50000,0.75,2,-4,"th_sun","th_suncover",100));
		
		
		AddNode(new CGravObject("Mercury",CVec3(-1.88,0,0),CVec3(0,-43.58,0),0.08,0.0402,2,"mercurymap",50));
	    AddNode(new CGravObject("Venus",CVec3(-2.72,0,0),CVec3(0,-36.23,0),1.22,0.052,2,"venusmap",115));
		AddNode(new CGravObject("Earth",CVec3(-3.5,0,0),CVec3(0,-31.94,0),1.22,0.1096,2,-4,"earthmap1k","earthcloudmap",175));
    	AddNode(new CGravObject("Mars",CVec3(-4.52,0,0),CVec3(0,-28.10,0),0.16,0.0584,2,"marsmap1k",250));
		AddNode(new CGravObject("Jupiter",CVec3(7.2,0,0),CVec3(0,29.88,0),250,0.45,2,"jupitermap",1250));
		AddNode(new CGravObject("Saturn",CVec3(12.54,0,0),CVec3(0,22.64,0),142,0.37,2,"saturnmap",1250));
	//	AddNode(new CGravObject("HyperComet",CVec3(15,0,15),CVec3(-12,0,-10),1,0.013*10,2,-4,"nr2-bump","SamothraceClouds",1250));
	//	AddNode(new CGravObject("HyperComet",CVec3(0,20,-10),CVec3(0,-8,+3),1,0.013*10,2,-4,"nr2-bump","SamothraceClouds",1250));
		AddNode(new CGravObject("Uranus",CVec3(-20.21,0,0),CVec3(0,-13.29,0),21.82,0.22,2,"uranusmap",1500));
		AddNode(new CGravObject("Neptune",CVec3(26.06,0,0),CVec3(0,15.70,0),25.75,0.212,2,"neptunemap",1500));
		AddNode(new CGravObject("Pluto",CVec3(-29.5,0,0),CVec3(0,-11.00,0),0.003,0.0192,2,"plutomap1k",1600));	
		
		
		
		
	//	AddNode(new CGravObject("Moon",CVec3(-3.7,0,0),CVec3(0,-32.72485325,0),0.1,0.025,2,-4,"nr2-bump","SamothraceClouds",100));
		





	}
};

class WhateverScene: public CScene
{
public:
	void Init()
	{
		NodeList.clear();
		
		SceneName = "Whatever Scene";						//	Specify the scenename

		fSpeed = 0.01;
		
		AddNode(new CGravObject("Sun",CVec3(0,0,0),CVec3(0,0,0),50000,0.3,2,-4,"th_sun","th_suncover",100));


		IgnoreMode();

		float gm = 50000*0.1;
		float trail = 6;

		for(int r =1; r <100; r+=2)
		{
			float v = sqrt(gm/r);
			AddNode(new CGravObject("HyperComet",CVec3(r,0,0),CVec3(0,v,0),1,0.013*10,2,-4,"nr2-bump","th_suncover",trail*r));
			AddNode(new CGravObject("HyperComet",CVec3(-r,0,0),CVec3(0,-v,0),1,0.013*10,2,-4,"nr2-bump","th_suncover",trail*r));
		}

		

		// Ima Build a loooping dyson swarm here
		//AddNode(new CGravObject("Blearth",CVec3(0,0,0),CVec3(0,0,0),1500,0.5,2,-1,"tim102","earthclouds",20));
		//AddNode(new CGravObject("Noom",CVec3(0,1.5,0),CVec3(0,0,6),100,0.2,2,-4,"nr2-bump","SamothraceClouds",40));
		//AddNode(new CGravObject("RockMoon",CVec3(0,-1.5,0),CVec3(0,0,-6),100,0.1,2,"nr2",100));
												
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