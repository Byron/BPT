// edgeMeshCreator.h: interface for the edgeMeshCreator class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EDGEMESHCREATOR_H__0FC9C2BD_E36E_4E59_BB37_85D73A318D17__INCLUDED_)
#define AFX_EDGEMESHCREATOR_H__0FC9C2BD_E36E_4E59_BB37_85D73A318D17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "meshCreator.h"
#include "edgeFaceData.h"



namespace BPT
{

/** Der EdgeMeshCreator implememtiert spezialisierte funktionen, welche von der BPTfty verwendet werden, er
	wird also insbesondere zum beveln ben�tigt

*/

class edgeMeshCreator : public meshCreator  
{
public:
	edgeMeshCreator(		MObject&		fMesh,
							double			inSlide, 
							MDagPath&		meshPath
															 );
	
	virtual ~edgeMeshCreator();

//---------------
//SLIDE METHODEN
//---------------

	void	addNormalSlide(int vtxID);										//!< speziell f�r vtxIDs der Edges
	void	addSlideAndNormal(int startID,int edgeVtx,MIntArray&  faces);	//!< nur f�r die neuen Vtx auf Edges

	void	addSlideAndNormal(int startID, int edgeVtx,MPoint& position, bool usePositionInstead = false);	//!< speziell f�r chamfer;

	void	addSlide(int startID,int endID);

	void	addUVSlide(const MFloatArray& startPositions,const MFloatArray& endPositions,const MIntArray& newUVIds);

	MPoint	getSlideStartPoint(int vtxID);
	
	void	getUVSlideStartPoint(const MIntArray& UVIDs, MFloatArray& outPos);

//--------------------------
//ZUGRIFFS METHODEN
//--------------------------

	MPoint	getWingedDisplacedPoint(int wingedVtx, MVector& preMultipliedNormal);
	
	MPoint	getVtxPoint(int ID){return (*vtxPoints)[ID];};

	void	setVtxPoint(int ID,MPoint& inPoint){ (*vtxPoints)[ID] = inPoint;};

	void	getFaceNormal(int faceID, MVector& inNormal);

	MPoint	getFaceCenter( int faceID ){polyIter.setIndex(faceID,tmp); return polyIter.center();}

	void	getFaceTriangles(int faceID, MIntArray& outTriVtx, MPointArray& outTriPoints);


//-------------------------------------
//MESH MODIFIKATOREN (EDGE SPEZIFISCH)
//-------------------------------------

	void	insertVtx(const edgeFaceData* faceData, int startID, int newID,int direction );
	
	void	removeVtx(int vtxID, int faceID);


	void	changePolyVtxIDs(const edgeFaceData* faceData);


	void	createPoly(MIntArray& vtxIDs, edgeFaceData* faceData);		//!< spezielisierte Variante von create Poly

	void	edgeMeshCreator::createPoly(const edgeFaceData* data);
	

	void	changeSideFace(int origVtxID, int newVtxID, int faceID, MIntArray& newUVIds );

	void	changeEndFace(int origVtxID,int newVtxID[],int directions[], edgeFaceData* faceData[2]);

	void	changeEndFace(int origVtxID,int newVtxID, int direction, edgeFaceData* faceData); //!< speziell f�r die endbereiche des chamfers
	


	int		addWingedDisplacedVtx(int wingedVtx, MVector& preMultipliedNormal);

	void	removeLastVtxPoint(){vtxPoints->remove(vtxPoints->length() - 1);};


	void	updateFaceData(edgeFaceData* faceData);
	

	void	recreateOriginalFace(edgeFaceData* origFace);




//-------------------------------------
//UV MESH
//-------------------------------------

	void		setUVPositions(MIntArray& UVIds, MFloatArray& UVPos);

	MIntArray	createUVs(MIntArray& validator, MFloatArray& UVPos);




//PRIVATE METHODEN
private:
	
	


};

}

#endif // !defined(AFX_EDGEMESHCREATOR_H__0FC9C2BD_E36E_4E59_BB37_85D73A318D17__INCLUDED_)
