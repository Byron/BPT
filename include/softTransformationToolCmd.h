// softTransformationTool.h: interface for the softTransformationTool class.
//
//////////////////////////////////////////////////////////////////////

#ifndef	SOFTTRANSFORMATIONTOOLCMD_H
#define SOFTTRANSFORMATIONTOOLCMD_H


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

#include	<MACROS.h>
#include	<progressBar.h>
#include	<BGlobals.h>



//-----------------------------------------------
//TOOL_COMMAND
//-----------------------------------------------
class softTransformationToolCmd : public MPxToolCommand
{
// ///////////////////////////////
//		  Konstruktion		  ///
public: //****************** ///
// ////////////////////////////

	softTransformationToolCmd(){/*cout<<"ERZEUGE UNDO CONTAINER: "<<counter<<endl;*/ number = counter++;};
    virtual ~softTransformationToolCmd(){/*cout<<"War im Destructor: "<<--counter<<endl;*/}; 


// ////////////////////////////////
//		  Öffentliche Methoden ///
public: //******************* ///
// /////////////////////////////

	MStatus     doIt(const MArgList &args);
    MStatus     redoIt();
    MStatus     undoIt();
    bool        isUndoable() const;
    MStatus		finalize();
   
// ///////////////////////////////
//		  Statische Methoden  ///
public: //****************** ///
// ////////////////////////////

	static void * creator();
	static int counter;


// /////////////////////////////////
//		  Öffentliche Variablen ///
public: //******************** ///
// //////////////////////////////
// ich machs mir mal einfach und verzichte auf jegliche kapselung
//
	int				number;
	
	MDagPath		meshPath;
	MIntArray		indexArray;

	//im undoModus werden die tweaks subtrahiert, im redomode addiert, aber nur, wenn tool nicht mehr das eigene
	//
	MVectorArray	undoTweaks;	
};




#endif // !defined(AFX_SOFTTRANSFORMATIONTOOL_H__6F784EDA_4CE2_46D0_A479_212171CAB53C__INCLUDED_)

