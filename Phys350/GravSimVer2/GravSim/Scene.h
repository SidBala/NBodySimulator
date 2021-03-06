
#pragma once

#include <vector>
#include "GravObject.h"
#include "PlanetDefs.h"

//	SubClass this class to create your own scenes
//	A Scene is a predefined setup of a gravitational system
//	Scene nodes such as planets and stars can be setup in PlanetDefs.h and PlanetDefs.cpp
//	A scene also offers functions to remove or add nodes
//	These Scenes will be added onto the SceneManager Class, which will further add
//	functionality to manipulate entire scenes for demoing various situations


class CScene
{
public:

	std::vector<CGravObject*> NodeList;
	std::vector<std::string> NodeNames;
	std::string SceneName;

	float fSpeed;
	int iIgnore;

	int iCameraFocus;

public:
	CScene(void);
	
	void DeleteNode(int NodeID);
	void AddNode(CGravObject *NewNode);
	void IgnoreMode();
	void UpdateNameLists();

	
	virtual void Init() = 0;		//	This will be where the planets will go

	inline bool IsEmpty()
	{
		return NodeList.empty();
	}

	~CScene(void);
};
