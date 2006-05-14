// endFaceData.cpp: implementation of the endFaceData class.
//
//////////////////////////////////////////////////////////////////////

#include "endFaceData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

endFaceData::endFaceData(	int inOrigVtx,
							int inNewVtx[2], 
							edgeFaceData* inFaceData[2], 
							int inConnectEnds[2], 
							int inDirections[2],
							int edgeID)
														:
																origVtx(inOrigVtx)
																
{
	newVtx[0] = inNewVtx[0];		newVtx[1] = inNewVtx[1];


	branding = edgeID;


	faceData[0] = inFaceData[0];	faceData[1] = inFaceData[1];

	directions[0] = inDirections[0];	directions[1] = inDirections[1];

	if(inConnectEnds[0] == -2)
	{//es ist quad mode
		connectEnds[0] = -2;
	}
	else
	{// es ist trimode
		connectEnds[0] = inConnectEnds[0];
		connectEnds[1] = inConnectEnds[1];
	}

}

endFaceData::~endFaceData()
{

}
