// Main.h: interface for the CMain class.
//
//////////////////////////////////////////////////////////////////////


#pragma once


class CMain  
{
public:
	
	virtual BOOL Initialize();
	virtual void Deinitialize();
	virtual void Update (DWORD milliseconds);
	virtual void Draw();

public:
	BOOL KeyPressed( int nCode );
		
	

	CMain();
	virtual ~CMain();

};
