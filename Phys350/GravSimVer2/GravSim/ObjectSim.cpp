#include "stdafx.h"
#include "ObjectSim.h"


//class CVec3;

static const float G = 0.1f;					//	Gravitational Constant
static int TrailLength = 500;

CObjectSim::CObjectSim(void)
{
	PerfObjectSim.CSName = CString("ObjectSim");		//Initialize the PerfCounter
}

CObjectSim::~CObjectSim(void)
{
}

void CObjectSim::SimUpdate(CScene *Scene)
{
	//PerfObjectSim.Start();					// Start the Performance Counter


	std::vector<CGravObject*> *ObjList = &(Scene->NodeList);

	std::vector<CGravObject*>::iterator	i;
	std::vector<CGravObject*>::iterator	j;

	CVec3	v3Dist;
	CVec3	v3Acc;

	float	fDist				= 0.0f;
	float	fCube				= 0.0f;
	float	fForceMag			= 0.0f; 
	float	dt					= 0.01f;		//(float)milliseconds / 1000;

	for(i = ObjList->begin(); i != ObjList->end() ; i++)				//	Set all initial positions to the last final positions
	{
		(*i)->v3Pi = (*i)->v3Pf;
		(*i)->v3Vi = (*i)->v3Vf;

		//Rotate the planets around

		(*i)->fRotPl = (*i)->fRotPl + (*i)->fRotvPl;
		if((*i)->fRotPl > 360) (*i)->fRotPl = 0;

		//Rotate the clouds around

		(*i)->fRotCl = (*i)->fRotCl + (*i)->fRotvCl;
		if((*i)->fRotCl > 360) (*i)->fRotCl = 0;


		//Add Trails here

		if((*i)->Trails.size() == TrailLength)
		{
			(*i)->Trails.erase((*i)->Trails.begin());
		}
		(*i)->Trails.insert((*i)->Trails.end(),(*i)->v3Pf);
	}

	for(i = ObjList->begin(); i != ObjList->end() ; i++)
	{
		v3Acc = CVec3(0.0f,0.0f,0.0f);

		for(j = ObjList->begin(); j != ObjList->end() ; j++)
		{
			if(i!=j)
			{
				v3Dist = (*j)->v3Pi - (*i)->v3Pi;
				
				fDist = v3Dist.Norm();
					
				if(fDist <= (*j)->fRadius)
					fCube = ((*j)->fRadius)*((*j)->fRadius)*((*j)->fRadius);
				else
					fCube = fDist*fDist*fDist;

				fForceMag = G * ((*j)->fMass / fCube);

				v3Acc = v3Acc + (v3Dist*fForceMag);
			}
		}

		(*i)->v3Vf = (*i)->v3Vi + (v3Acc * dt);
		(*i)->v3Pf = (*i)->v3Pi + ((*i)->v3Vf * dt);
	}
	
	
	Scene->UpdateNameLists();		//	This is required if there are completely inelastic collisions
}
