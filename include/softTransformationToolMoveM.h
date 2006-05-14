// softTransformationTool.h: interface for the softTransformationTool class.
//
//////////////////////////////////////////////////////////////////////

#ifndef	SOFTTRANSFORMATIONTOOLMOVEM_H
#define SOFTTRANSFORMATIONTOOLMOVEM_H

///////////////////////////
// MAYA INCLUDES	   ///
/////////////////////////

#include	<maya/MPxContextCommand.h>
#include	<maya/MPxToolCommand.h>
#include	<maya/MPxSelectionContext.h>
#include	<maya/MPxContext.h>
#include	<maya/MPxManipContainer.h>
#include	<maya/MArgList.h>
#include	<maya/MStatus.h>
#include	<maya/MDagPath.h>
#include	<maya/MFnFreePointTriadManip.h>
#include	<maya/MFnStateManip.h>
#include	<maya/MFnDiscManip.h>
#include	<maya/MModelMessage.h>
#include	<maya/MDGModifier.h>
#include	<maya/MGlobal.h>
#include	<maya/MSelectionList.h>
#include	<maya/MItSelectionList.h>
#include	<maya/MFnTransform.h>
#include	<maya/MPoint.h>
#include	<maya/MIntArray.h>
#include	<maya/MFnIntArrayData.h>
#include	<maya/MFnSingleIndexedComponent.h>
#include	<maya/MItMeshVertex.h>
#include	<maya/MItMeshEdge.h>
#include	<maya/MItMeshPolygon.h>
#include	<maya/MFnNumericData.h>
#include	<maya/MFnMesh.h>
#include	<maya/MFnDependencyNode.h>
#include	<maya/MFnDagNode.h>
#include	<maya/MBoundingBox.h>
#include	<maya/MPlugArray.h>
#include	<maya/MManipData.h>
#include	<maya/MFnNumericData.h>
#include	<maya/MEulerRotation.h>
#include	<maya/MFnVectorArrayData.h>
#include	<maya/MVectorArray.h>
#include	<maya/MFnMatrixData.h>
#include	<maya/MMatrix.h>
#include	<maya/MString.h>
#include	<maya/MAnimUtil.h>
#include	<maya/MFnAnimCurve.h>
#include	<maya/MArgParser.h>
#include	<maya/MFnToggleManip.h>
#include	<maya/MDagModifier.h>
#include	<maya/MFnCamera.h>
#include	<maya/MDGMessage.h>


#include	<math.h>

///////////////////////////
// EIGENE INCLUDES	   ///
/////////////////////////

#include	<MACROS.h>
#include	<progressBar.h>
#include	<BGlobals.h>



//-----------------------------------------------
//MANIPULATOR
//-----------------------------------------------

// ---------------------------------------------
class moveManip : public MPxManipContainer
// ---------------------------------------------
{

// ///////////////////////////////
//		    Konstruktion	  ///
public: //****************** ///
// ////////////////////////////

    moveManip(){};
    virtual ~moveManip(){};
    

// ///////////////////////////////
//		  Statische Methoden  ///
public: //****************** ///
// ////////////////////////////

    static void * creator();
    static MStatus initialize();
    virtual MStatus createChildren();
    virtual MStatus connectToDependNode(const MObject &node);


    virtual void draw(M3dView &view, 
					  const MDagPath &path, 
					  M3dView::DisplayStyle style,
					  M3dView::DisplayStatus status);
	
	void	calculateScaleFactor();

// ////////////////////////////
//		  Hilfsmethoden  ///
private: //************ ///
// ///////////////////////

	MManipData	setPointCB(unsigned index);
	MManipData	setPointCB2(unsigned index);
	MManipData	setDiscPointCB(unsigned index);
	MManipData	setDiscPointCB2(unsigned index);
	MManipData	getPlugTranslation();
	MManipData	getCachedTranslation(double xOffset,double yOffset,double zOffset);

	
 
	
	MDagPath	findMeshPath(const MObject& node) const;

    MDagPath fFreePointManip;
	MDagPath fDiscManip;
	MDagPath fDiscManip2;
	MDagPath fToggleManip;
	
	MDagPath fStateManip;	//steuert die FalloffType

public:
    static MTypeId id;


// /////////////////////////////
//		  Private Variablen ///
private: //************    ///
// //////////////////////////

	bool isOrthoCam;

	MFnTransform transFn;
	MVector	translation;
	double bbScaleFactor;
	M3dView	view;
	unsigned int freePointIndex;

};



#endif 

