// dData.cpp: implementation of the dData class.
//
//////////////////////////////////////////////////////////////////////

#include "dData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

dData::dData()//:isFlipped(false)
{}

dData::dData(int startLoc,int endLoc, int cStartLoc,int cEndLoc,int startAbs,int endAbs,int cStartAbs,int cEndAbs,int type,int requester,int inNachbarID)
:startLocID(startLoc), endLocID(endLoc), startLocCorner(cStartLoc), endLocCorner(cEndLoc), startAbsID(startAbs),
endAbsID(endAbs),startAbsCorner(cStartAbs),endAbsCorner(cEndAbs), typeInfo(type),requesterID(requester),nachbarID(inNachbarID),
isFlipped(false)
{}

dData::~dData()
{

}
