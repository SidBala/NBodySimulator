#pragma once

#include <vector>
#include "GravObject.h"
#include "PerfTool.h"

class CObjectSim
{
public:
	CPerfCounter PerfObjectSim;

public:
	CObjectSim(void);
	void SimUpdate(DWORD milliseconds, std::vector<CGravObject*> *ObjList);

	~CObjectSim(void);
};
