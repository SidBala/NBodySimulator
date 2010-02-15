#pragma once

#include <vector>
#include "GravObject.h"

class CObjectSim
{
public:
	CObjectSim(void);
	void SimUpdate(DWORD milliseconds, std::vector<CGravObject> *ObjList);

	~CObjectSim(void);
};
