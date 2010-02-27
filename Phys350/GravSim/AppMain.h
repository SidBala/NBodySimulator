// Main.h: interface for the CMain class.
//
//////////////////////////////////////////////////////////////////////

#include "planetdefs.h"
#include <vector>

#pragma once


class CMain  
{
public:
	
	virtual BOOL Initialize();
	virtual void Deinitialize();
	virtual void Update (DWORD milliseconds);
	virtual void Draw(std::vector<CGravObject*> *ObjList);

	float fRotX,fRotY,fRotZ;
	float fTransX,fTransY,fTransZ;
	
public:
	BOOL KeyPressed( int nCode );
		
	

	CMain();
	virtual ~CMain();

};
