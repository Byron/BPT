// vertexFty.h: interface for the vertexFty class.
//
//////////////////////////////////////////////////////////////////////

#ifndef VTXFTY_INCLUDE
#define VTXFTY_INCLUDE

#include "meshCreator.h"
#include "BPT_Helpers.h"
#include "BPT_BA.h"

#include <maya/MIntArray.h>
#include <maya/MPointArray.h>


#include <list.h>

using std::list;


namespace BPT
{

/** Diese Klasse ist in der Lage, die selektierten Vertizen zu verbinden wenn m�glich
	
*/

class vertexFty  
{
//------------------
//KONSTRUKTOREN
public:
//------------------

	vertexFty(	MIntArray* inSelVtxIDs, 
				meshCreator* inCreator,
				int	inSpin = 0);

	~vertexFty();

//------------------
//ARBEITSMETHODEN
public:
//------------------
	void	doIt();



//------------------
//PRIVATE HELFERMETHODEN
private:
//------------------
	
	//ConditionChecks für connect, können auf ptr gespeichert werden
	bool	isSelected				(UCHAR value);
	bool	gimmeFalse				(UCHAR value);

	//* erzeugt und verifiziert face
	bool	createFace				(	UINT tsb,					
										UINT teb,
										UCHAR* flags,
										MIntArray& faceVtx, 
										MIntArray& result	);		

	//* erzeugt und verifiziert Face anderen Typs
	bool	createExtraFace			(	UINT* bounds,				
										UCHAR* flags, 
										MIntArray& faceVtx, 
										MIntArray& result		);

	//* ueberprueft, ob das erzeugte Face in ordnung ist (also keine NullFläche hat)
	bool	checkFaceIntegrity		(	MIntArray& VtxList	);	
	
	
	void	splitFace(					
										MIntArray& faceVtx, 
										MIntArray& matchVtx	,
										int faceID				);


//------------------
//PRIVATE ELEMENTE
private:
//------------------

#ifdef DEBUG
	BPT_Helpers		helper;			//!< helper - wird nur für printArray benötigt
#endif

	meshCreator*	ftyCreator;

	MIntArray*		selVtxIDs;

	int				spin;			//!< default ist 0

	double			refValue;		//!< hält die Größe des Faces, welches gerade bearbeitet wird

//----------
//KONSTANTEN
private:
//----------
	static const UINT null; //!< null (0)
	static const UCHAR is;	//!< isSelected
	static const UCHAR iv;  //!< isValid

};

}

#endif
