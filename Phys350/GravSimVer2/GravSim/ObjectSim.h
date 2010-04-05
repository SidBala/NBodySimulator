#pragma once

#include <vector>
#include "GravObject.h"
#include "PerfTool.h"
#include "Scene.h"

class CObjectSim
{
public:
	CPerfCounter PerfObjectSim;

public:
	CObjectSim(void);
	void SimUpdate(CScene *Scene);

	~CObjectSim(void);
};
