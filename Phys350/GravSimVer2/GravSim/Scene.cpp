#include "StdAfx.h"
#include "Scene.h"

CScene::CScene(void)
{
	iCameraFocus = -1;
}

void CScene::DeleteNode(int NodeID)
{
	std::vector<CGravObject*>::iterator	i = NodeList.begin() + NodeID;
	NodeList.erase(i);

	UpdateNameLists();
}
void CScene::AddNode(CGravObject *NewNode)
{
	NodeList.push_back(NewNode);
	
	UpdateNameLists();
}

void CScene::UpdateNameLists()
{
	std::vector<CGravObject*>::iterator	i = NodeList.begin();

	NodeNames.clear();

	for(i = NodeList.begin(); i != NodeList.end();i++)
	{
		NodeNames.push_back((*i)->strName);
	}
}

CScene::~CScene(void)
{
	NodeList.clear();
}
