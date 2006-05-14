// nSelEdge.h: interface for the nSelEdge class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NSELEDGE_H__4781B204_A3AC_4509_A96B_9DF3C36D8D38__INCLUDED_)
#define AFX_NSELEDGE_H__4781B204_A3AC_4509_A96B_9DF3C36D8D38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "edge.h"



namespace BPT
{

/** diese Klasse dient als DatenKapsel und stellt ein nicht selecetete edge dar 
	
*/

class nSelEdge : public edge
{

public:
	nSelEdge(int inID);
	nSelEdge(MIntArray inFaceIDs,int inID);

	virtual ~nSelEdge();

public:
//-------------------------------------
//HAUPT METHODEN	
//-------------------------------------
//
	virtual	void	engageBevel(int connectEnds, int triangulateEnds, bool isSC){};



	void			changeFace(int origVtx, int newVtx,const edgeFaceData* faceData, UINT recurseCount);

public:
//-------------------------------------
//ZUGRIFFS METHODEN	
//-------------------------------------
//
	int				getRefDirection(int startVtx, int dirClue );

	int				getRefVtxID(int endVtx, bool special = false);
	
	void			setGerade(MDoubleArray gerade);

	virtual			MDoubleArray getGerade(bool displace,const edge* requester,bool useUId = false, int uniqueID = -1); 
	virtual	bool	isSelected(){return false;};


	void			getMaxRecurseCount(UINT* zeroNumber, const edge* startPtr) const;			//!< schaut, mit vievielen nachbarn diese edge verknüpft ist


	
//////////////////////////////////
//DoNothung Zeug//
//////////////////////////////////
//geerbte virtuelle Methoden von Edge, die aber nur von SelEdge benutzt werden

	virtual edge*			findNextSelEdge(edge* lastEdge);

	virtual MIntArray		getNewVtx() const {return MIntArray();};

	virtual	const int*		getUIDs() const{return 0;};
	
	virtual	int				getValidRichtung(int uniqueID){return -1;};

	virtual	void			setNewVerts(const edge* requester, MIntArray& newVerts,bool useUID = false, int uniqueID = 0){} //!< doNothing

	virtual int				getNewGeradenVtx(const edge* requester){return -1;}; //!< doNothing

	virtual void			setUIDs(MIntArray& IDs){};

	virtual void			getValidRichtung(const edge* requester, int& seite, int& richtung, int uniqueID = -1){return;};

	virtual	void			setThisFaceDataZero(void* thisFaceData){return;};

private:
//-------------------------------------
//DATENELEMENTE METHODEN	
//-------------------------------------

	double					gerade[6];

};


}

#endif // !defined(AFX_NSELEDGE_H__4781B204_A3AC_4509_A96B_9DF3C36D8D38__INCLUDED_)
