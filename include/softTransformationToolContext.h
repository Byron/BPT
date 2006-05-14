// softTransformationTool.h: interface for the softTransformationTool class.
//
//////////////////////////////////////////////////////////////////////

#ifndef	SOFTTRANSFORMATIONTOOLCONTEXT_H
#define SOFTTRANSFORMATIONTOOLCONTEXT_H

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
#include	<softTransformationToolCmd.h>
#include	<softTransformationToolMoveM.h>


// Foreward Deklarations
// ----------------------
	void	update(void * data);
	void	nodeRemovedCB(MObject& node, void* data);
	class	softTransformationToolCtxCommand;


//-----------------------------------------------
//SELECTION_COMTEXT
//-----------------------------------------------
//--------------------------------------------------------------
class softTransformationToolCtx : public MPxSelectionContext
//--------------------------------------------------------------
{
	// ----------
	// FRIENDS
	//

	friend void update(void * data);
	friend void	nodeRemovedCB(MObject& node, void* data);
	friend class	softTransformationToolCtxCommand;

// ///////////////////////////////
//		  Konstruktion		  ///
public: //****************** ///
// ////////////////////////////

    softTransformationToolCtx();
	virtual ~softTransformationToolCtx(){};


// ///////////////////////////////////
//		  Überschriebene Methoden ///
public: //********************** ///
// ////////////////////////////////


    virtual void    toolOnSetup(MEvent &event);
    virtual void    toolOffCleanup();
    virtual MStatus doPress(MEvent &event);
    virtual MStatus doDrag(MEvent &event);
    virtual MStatus doRelease(MEvent &event);
    virtual MStatus doEnterRegion(MEvent &event);


// /////////////////////////////////////
//		  Öffentliche Hilfsmethoden ///
private: //************************ ///
// //////////////////////////////////

	void	connectSoftNode(MObject& softNode,MObject& meshNode);	
	bool	selectionsDiffer(MSelectionList& list);	//vergleicht componenten zweier listen
	void	calculateScaleFactor();	//berechnet den BBScaleFactor
	bool	getVtxSelection(MIntArray& elements, MPoint& point,MDagPath& selObj, MObject& comps);
	
	void	careAboutVNode(bool deleteIt = false);


	bool	writeBackTweaks();	//beachtet Undo/redo;
	bool	generateUndoInfo();	//erzeugt nur die undoInfo für den Command, den eignentlich writeBackTweak hätte machen müssen
	bool	changeDistance(double value);
	bool	changeMask(int value);
	MObject	findSoftNode();

// ////////////////////////////////
//		  Private Variablen ///
private: //*************** ///
// //////////////////////////

	MPxToolCommand* 	myNewToolCmd(){return MPxSelectionContext::newToolCommand();}

    moveManip* moveM;	//manpulator
	softTransformationToolCmd * cmd;

	MDagModifier*	copyDagMod;
	MDGModifier*	dgModFn;
	MDGModifier*	animCreator;
	MFnAnimCurve	animFn;
	MDGModifier*	softConnector;	//dient speziell der connection der softNode
	MDagPath		lastMesh;
	MSelectionList	lastSelection;	//um auszuschließen, dass er auch bei drags updated

	
	/// Dient der Erzeugung der FastTrgNode, um die Tweaks zu beschleunigen
	//
	MDGModifier*	fastTrgNodeCreator;
	
		


	int			fType;
	bool		fVis;
	double		lastDistance;
	bool		useLastDistance;
	bool		nirFlag;	//normal is relative flag
	bool		cmdFinalized;

	bool		hasManip;
	
	
	MPoint		manipPos;
	bool		emergency;	//tritt auf, wenn mesh gelöscht wird, auf dem man arbeitet
	bool		hasHistory;



	
    M3dView view;
    
	MDagPath dupMeshDagPath;
	

	MDagModifier*	vmCreator;
	MDGModifier*	vmConnector;
	MDagPath		locatorPath;

	bool	noSGAssigned();
	
	bool isOrthoCam;

	double initialDist;
	int initialMask;
	double	bbScaleFactor;		//scaleFactor, der sich aus der BoundingBox ergibt
	short startPos_x, endPos_x, start_x, last_x;
    short startPos_y, endPos_y, start_y, last_y;

	/// Hält die Breite des Screens in Welteinheiten und dient der Normalisierung der stepSize der Distanz
	//
	float maxScreenDistance;
    
};



#endif 
