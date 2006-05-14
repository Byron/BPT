// componentConverter.h: interface for the componentConverter class.
//
//////////////////////////////////////////////////////////////////////

#ifndef COMPONENTCONVERTER_INCLUDE
#define COMPONENTCONVERTER_INCLUDE

#include "BPT_BA.h"


#include <maya/MIntArray.h>
#include <maya/MObject.h>
#include <maya/MFnMesh.h>
#include <maya/MItMeshVertex.h>
#include <maya/MItMeshEdge.h>
#include <maya/MItMeshPolygon.h>


namespace BPT
{

/** Einfache KapselKlasse, welche hilfsmethoden beinhaltet, die speziell f¸r die umwandlung von polygoncomponenten
	gemacht sind.

	Die Namen der Funktionen sind selbsterkl‰rend

*/

class componentConverter 
{

//------------------
//KONSTRUKTION
public:
//------------------

	componentConverter(MObject& mesh);
	~componentConverter();

//------------------
//ARBEITSMETHODEN
public:
//------------------

void		getContainedEdges(	MIntArray& vtxIDs,
								MIntArray& result	);

void		getConnectedFaces(MIntArray& edgeIDs,
							  MIntArray& result		);

void		vtxToConnectedFaceVtx(const	MIntArray&		vtxIDs, 
										MIntArray&		outFaceVtx);




//------------------
//PRIVATE DATENELEMENTE
private:
//------------------
MObject		mesh;			//h√§lt das mesh, auf dem gearbeitet wird
int			tmp;			//wird f√ºr.setIndex der iteratoren ben√∂tigt


};

}

#endif
