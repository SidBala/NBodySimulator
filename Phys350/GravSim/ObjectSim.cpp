#include "stdafx.h"
#include "ObjectSim.h"

class CVec3;


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
	v3Acc = v3Dist;
	float fDist	= 0.0f;
	float fDistCube = 0.0f;
	float fForceMag = 0.0f; 

	

	for(i = ObjList->begin(); i != ObjList->end() ; i++)
	{
		i->v3Pi = i->v3Pf;
		i->v3Vi = i->v3Vf;

		for(j = ObjList->begin(); j != ObjList->end() ; j++)
		{
			if(i!=j)
			{
				v3Dist = j->v3Pi - i->v3Pi;
				
				fDist = v3Dist.Norm();

				fDistCube = fDist*fDist*fDist;
				//fRadiusCube = f

			//	if(fDist <= j->fRadius)
			//		fForceMag = (j->fMass / fDistCube)

			//	fForceMag = (j->fMass / fDistCube)

				v3Acc = v3Acc + ((j->fMass / fDistCube) * v3Dist);
			}
		}
	}
}
