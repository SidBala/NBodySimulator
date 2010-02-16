#include "stdafx.h"
#include "ObjectSim.h"

//class CVec3;

static const float G = 1.0f;					//	Gravitational Constant

CObjectSim::CObjectSim(void)
{
	
}

CObjectSim::~CObjectSim(void)
{
}

void CObjectSim::SimUpdate(DWORD milliseconds, std::vector<CGravObject> *ObjList)
{
	std::vector<CGravObject>::iterator i;
	std::vector<CGravObject>::iterator j;

	CVec3 v3Dist;
	CVec3 v3Acc;

	float fDist	= 0.0f;
	float fCube = 0.0f;
	float fForceMag = 0.0f; 
	float dt = (float)milliseconds / 1000;

	for(i = ObjList->begin(); i != ObjList->end() ; i++)				//	Set all initial positions to the last final positions
	{
		i->v3Pi = i->v3Pf;
		i->v3Vi = i->v3Vf;
	}

	for(i = ObjList->begin(); i != ObjList->end() ; i++)
	{
		v3Acc = CVec3(0.0f,0.0f,0.0f);

		for(j = ObjList->begin(); j != ObjList->end() ; j++)
		{
			if(i!=j)
			{
				v3Dist = j->v3Pi - i->v3Pi;
				
				fDist = v3Dist.Norm();
					
				if(fDist <= j->fRadius)
					fCube = (j->fRadius)*(j->fRadius)*(j->fRadius);
				else
					fCube = fDist*fDist*fDist;

				fForceMag = G * (j->fMass / fCube);

				v3Acc = v3Acc + (v3Dist/fForceMag);
			}
		}

		i->v3Vf = i->v3Vi + (v3Acc * dt);
		i->v3Pf = i->v3Pi + (i->v3Vf * dt);
	}
}
