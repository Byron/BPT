// endFaceData.h: interface for the endFaceData class.
//
//////////////////////////////////////////////////////////////////////

#ifndef	ENDFACEDATA
#define ENDFACEDATA




#include "edgeFaceData.h"


namespace BPT
{

/** diese Klasse dient als DatenKapsel für Daten, die ein Face so bekommt, wenn es von edges während des Chamfers verändert wird
	
*/


class endFaceData  
{
//----------------------------
//KONSTRUKTION - DESTRUKTION
public:
//----------------------------
	
	endFaceData(	int origVtx, 
					int newVtx[2], 
					edgeFaceData* faceData[2], 
					int connectEnds[2], 
					int inDirections[2],
					int edgeID);			//!< wenn für connectEnds ein nullPtr gegeben wird heisstdas, dass quads erstellt werden sollen
	~endFaceData();

//----------------------------
//VARIABLEN
public:
//----------------------------

	int origVtx;
	int newVtx[2];
	edgeFaceData* faceData[2];
	int connectEnds[2];			//!< werte bestimmen modus; ce[0] == -2 -> createQuads, ansonsten 0, wenn CE false, 1 wenn true -> in diesen Fällen wird sowieso trianguliert
	
	int directions[2];			//!< besagt, ob der refVtx in faceRictung zeigt (true), oder nicht

	int branding;				//!< hält die edgeID der edge, die diese instanz erstellt hat. Wird von chamfer benötigt, um später seine faces wiederzufinden, irrelevant für SC
};


}

#endif ENDFACEDATA
