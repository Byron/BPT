// nSelEdgeData.h: interface for the nSelEdgeData class.
//
//////////////////////////////////////////////////////////////////////

#ifndef	NSELEDGEDATA
#define NSELEDGEDATA



#include "edgeFaceData.h"



namespace BPT
{

/** diese Klasse dient als DatenKapsel
	
*/

class nSelEdgeData  
{
//----------------------------
//KONSTRUKTION - DESTRUKTION
public:
//----------------------------
	nSelEdgeData(void* nSelEdge, int origID, int newID, edgeFaceData* faceData);
	~nSelEdgeData();


//----------------------------
//VARIABLEM
public:
//----------------------------
	void* nSelEdge;		

	int origID;
	int newID;

	const edgeFaceData* faceData;

};

}

#endif 
