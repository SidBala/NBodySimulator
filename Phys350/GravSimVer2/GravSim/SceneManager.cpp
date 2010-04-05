#include "StdAfx.h"
#include "SceneManager.h"


CSceneManager::CSceneManager(void)
{
	InitializeCriticalSection(&SceneManagerCS);
	IsInit = false;

	SceneList.push_back(new DefaultScene);
	SceneList.push_back(new WhateverScene);
	CurrentScene = SceneList[0];
}

void CSceneManager::Init(CObjectSim* ObjSim, COpenGLControl* OglControl)
{
	if(!IsInit)
	{
		mSim = ObjSim;
		mRenderer = OglControl;
	}

	ChangeScene(0);		//	Set the default Scene

	IsInit = true;

}

void CSceneManager::RunScene()
{
	if(!IsInit) return;

	Lock();

	mSim->SimUpdate(CurrentScene);
	mRenderer->oglDrawScene(CurrentScene);


	Unlock();
}

void CSceneManager::DeleteNode(int id)
{
	Lock();
	if(!CurrentScene->IsEmpty())
	{
		LOG("\nDeleting Object %s from %s",CurrentScene->NodeNames[id].data(),CurrentScene->SceneName.data());
		CurrentScene->DeleteNode(id);

	}
	Unlock();
}
void CSceneManager::AddNode(CGravObject* Node)
{
	Lock();
	CurrentScene->AddNode(Node);
	Unlock();

}
void CSceneManager::ChangeScene(int id)
{
	Lock();	
	std::vector<CScene*>::iterator	i = SceneList.begin() + id;
	LOG("\nChanging Scene from %s to %s",CurrentScene->SceneName.data(),(*i)->SceneName.data());
	CurrentScene = (*i);
	Unlock();
}

CSceneManager::~CSceneManager(void)
{
	Lock();
	SceneList.clear();
	Unlock();
}
