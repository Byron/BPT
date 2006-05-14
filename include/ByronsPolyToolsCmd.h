#ifndef _ByronsPolyTools
#define _ByronsPolyTools

#include "polyModifierCmd.h"
#include "BPTfty_NH.h"

// Function Sets
//
#include <maya/MFnComponentListData.h>
#include <maya/MSyntax.h>
#include <maya/MArgDatabase.h>
#include <maya/MGlobal.h>
#include <maya/MIntArray.h>
#include <maya/MSelectionList.h>
#include <maya/MIntArray.h>

#include <maya/M3dView.h>

#include <BPTNodeManip.h>








namespace BPT
{

/** Diese Klasse wird direkt von maya gerufen und bereitet alles vor, um die Nodes erstellen zu k�nnen, welche f�r 
	operation ben�tigt werden
	
*/

class ByronsPolyTools : public polyModifierCmd
{

public:
		
	ByronsPolyTools();
	virtual						~ByronsPolyTools();

	static		void*			creator();
	static		MSyntax			newSyntax();


	virtual bool			isUndoable() const;

	virtual MStatus			doIt( const MArgList& );
	virtual MStatus			undoIt();
	virtual MStatus			redoIt();

	


	/////////////////////////////
	// polyModifierCmd Methods //
	/////////////////////////////

	virtual MStatus			initModifierNode( MObject modifierNode );
	virtual	MStatus			directModifier( MObject mesh );
	

	private:
	/////////////////////
	// Private Methods //
	/////////////////////

	//Noch Methoden hinzuzufügen

	//schreiben entsprechende IntArrays
				MStatus			setActionMode();
				void			getPolyComponents(MSelectionList &sList);
				void			getVertComponents(MSelectionList &sList);
				void			getEdgeComponents(MSelectionList &sList);

				void			convertToEdges(MSelectionList& sList, bool doNotConvertVertices);	//!< wandelt die verts und Faces in contained edges um
				

				virtual void	getModifierUINodeName(MString& newName);	//!< gibt passenden namen für die Node zurück, die gerade erstellt wurde
	//////////////////
	// Private Data //
	//////////////////

	
	//
	// Note: The MObject, fComponentList, is only ever accessed on a single call to the plugin.
	//		 It is never accessed between calls and is stored on the class for access in the
	//		 overriden initModifierNode() method.
	//
//	++++++++
//	+ARRAYS+
//	++++++++
				
MIntArray	vertIDs;
MIntArray	edgeIDs;
MIntArray	polyIDs;

	//undoInfo
	MSelectionMask	undoMask;

	MObject						components;

	//Flags für BPT
	//----------------
	bool	smartSplitFlagSet, 
			edgeLoopFlagSet, 
			edgeRingFlagSet, 
			boundaryFlagSet, 
			chamferFlagSet, 
			solidChamferFlagSet,
			smcFlagSet,
			growFlagSet,
			schrinkFlagSet;

	int slideIsRelative;
	int normalIsRelative;

	int CMDactionMode;

	///initialSettings
	bool avt, avm;


	
	//Flags für insert VTX
	//----------------

	unsigned int initialCount;

	//-----------------
	
	unsigned int operationMode;	//!< gibt an, welche node erstellt werden soll, und welche Flags gelesen werden
	
	double directSlide; //!< SlideWert, wenn er als Flag übergeben wird und keine Node erstellt wird

	MSelectionList	origList;

	MDagPath meshDagPath;

	MIntArray	options;


	
	MObject bptNode;	//!< beinhaltet den Namen der neuen BPTNode (für scripter zur Steuerung der node)
	
	// ByronsPolyTools Factory NO History - erledigt alle selection aufgaben, so dass der Command wirklich nur das hat was 
	//er wirklich benötigt

	BPTfty_NH				fBPTfty;
};

}

#endif
