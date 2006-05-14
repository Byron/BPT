// nSelEdgeData.cpp: implementation of the nSelEdgeData class.
//
//////////////////////////////////////////////////////////////////////

#include "nSelEdgeData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

nSelEdgeData::nSelEdgeData(	void*		inNSelEdge, 
							int			inOrigID, 
							int			inNewID, 
							edgeFaceData* inFaceData)
												:
													nSelEdge(inNSelEdge), 
													origID(inOrigID), 
													newID(inNewID),
													faceData(inFaceData)
{

}

nSelEdgeData::~nSelEdgeData()
{

}
