#pragma once

#include "Scene.h"
#include "SceneDefs.h"
#include "ObjectSim.h"
#include "OpenGLControl.h"

class CSceneManager
{
public:
	std::vector<CScene*> SceneList;
	std::vector<std::string> SceneNames;
	CScene *CurrentScene;

	CObjectSim	*mSim;
	COpenGLControl *mRenderer;

	CRITICAL_SECTION SceneManagerCS;

public:

	
	CSceneManager(CObjectSim* ObjSim, COpenGLControl* OglControl);
	
	CSceneManager();
	~CSceneManager(void);

	void Init(CObjectSim* ObjSim, COpenGLControl* OglControl);
	void DeleteNode(int id);
	void AddNode(CGravObject* Node);
	void ChangeScene(int id);
	void RunScene();

	bool IsInit;

	inline void Lock()
	{
		EnterCriticalSection(&SceneManagerCS);
	}

	inline void Unlock()
	{
		LeaveCriticalSection(&SceneManagerCS);
	}


};
