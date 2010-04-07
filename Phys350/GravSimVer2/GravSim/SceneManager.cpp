#include "StdAfx.h"
#include "SceneManager.h"


//	Add all scenes here
CSceneManager::CSceneManager(void)
{
	InitializeCriticalSection(&SceneManagerCS);
	IsInit = false;
	IsPaused = false;

	AddScene(new DefaultScene);
	AddScene(new WhateverScene);
	AddScene(new BlackHole);
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

	if(!IsPaused)						//	Dont Move the objects if pause is on
	mSim->SimUpdate(CurrentScene);

	mRenderer->oglDrawScene(CurrentScene);


	Unlock();
}
void CSceneManager::TogglePause()
{
	Lock();
		IsPaused = !IsPaused;
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

void CSceneManager::ResetCurrentScene()
{
	Lock();
	CurrentScene->Init();
	Unlock();
}

void CSceneManager::AddScene(CScene *Scene)
{
	Lock();
	Scene->Init();
	SceneList.push_back(Scene);
	UpdateNameList();
	Unlock();
}

void CSceneManager::UpdateNameList()
{
	std::vector<CScene*>::iterator	i = SceneList.begin();
	
	SceneNames.clear();
	
	for(i = SceneList.begin(); i != SceneList.end();i++)
	{
		SceneNames.push_back((*i)->SceneName);
	}
}

CSceneManager::~CSceneManager(void)
{
	Lock();
	SceneList.clear();
	SceneNames.clear();
	Unlock();
}
