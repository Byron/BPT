// INTERACTIVETWEAKTOOL.h: interface for the INTERACTIVETWEAKTOOL class.
//
//////////////////////////////////////////////////////////////////////

#ifndef INTERACTIVETWEAKTOOL_H
#define INTERACTIVETWEAKTOOL_H

// -------------------------------------
//	MAYA INCLUDES
// -------------------------------------

#include	<maya/MPxContextCommand.h>
#include	<maya/MPxToolCommand.h>
#include	<maya/MPxContext.h>


#include	<maya/M3dView.h>

#include	<maya/MArgList.h>
#include	<maya/MArgParser.h>

#include	<maya/MStatus.h>
#include	<maya/MDagPath.h>

#include	<maya/MModelMessage.h>
#include	<maya/MDGMessage.h>

#include	<maya/MDGModifier.h>
#include	<maya/MGlobal.h>
#include	<maya/MSelectionList.h>
#include	<maya/MFnTransform.h>
#include	<maya/MPoint.h>
#include	<maya/MIntArray.h>
#include	<maya/MFnDependencyNode.h>
#include	<maya/MFnDagNode.h>
#include	<maya/MPlug.h>
#include	<maya/MPlugArray.h>
#include	<maya/MString.h>
#include	<maya/MItSelectionList.h>
#include	<maya/MFnNumericAttribute.h>
#include	<maya/MFnEnumAttribute.h>


// -------------------------------------
//	EIGENE INCLUDES
// -------------------------------------

#include    <MACROS.h>

#include	<BPTGlobalPrequesites.h>

#include	<UI_container.h>

#include	<UI_textBox.h>

#include	<UI_generalSlider.h>
// -------------------------------------
//	DIVERSE INCLUDES
// -------------------------------------

#include	<math.h>







//-----------------------------------------------
//TOOL_COMMAND
//-----------------------------------------------
// -------------------------------------------------------
class interactiveValueTweakCmd : public MPxToolCommand
// -------------------------------------------------------
{
// -----------------
// Konstruktion/ Destruktion
public:
// -----------------

	interactiveValueTweakCmd(){};
    virtual ~interactiveValueTweakCmd(){}; 

// ---------------------
// Überladene Methoden
public:
// ---------------------

    MStatus     doIt(const MArgList &args);
    
	MStatus     redoIt();
    MStatus     undoIt();
    
	bool        isUndoable() const;
    
	MStatus		finalize();

    
public:
    static void * creator();

};


//-----------------------------------------------
//SELECTION_COMTEXT
//-----------------------------------------------
//--------------------------------------------------------------
class interactiveValueTweakCtx : public MPxContext
//--------------------------------------------------------------
{

// -----------------
// Konstruktion/ Destruktion
public:
// -----------------

    interactiveValueTweakCtx();
	virtual ~interactiveValueTweakCtx(){};

// ------------------------------------
// Überladene, redefinierte Methoden
public:
// ---------------------------------------

    virtual void    toolOnSetup(MEvent &event);
    virtual void    toolOffCleanup();

    virtual MStatus doPress(MEvent &event);
    virtual MStatus doDrag(MEvent &event);
    virtual MStatus doRelease(MEvent &event);
    
	virtual MStatus doEnterRegion(MEvent &event);



// ------------------------------------
// Private Methoden
private:
// ------------------------------------
	
	///schreibt werte der plugs im keyables Array als string in attrValues
	void	getValues();	


// ------------------------------------
// Private Variablen
private:
// ------------------------------------


    M3dView view;
    
	MPlugArray		keyables;
	MStringArray	attrNames;	//namen der Attribute
	MStringArray	attrValues;	


	bool	isValidSession;
	
	/// Container für alle zu erzeugenden Elemente
	UI_container*	ui;

    
};


//-----------------------------------------------------
//CONTEXT_COMMAND
//-----------------------------------------------------

//--------------------------------------------------------------
class interactiveValueTweakCtxCommand : public MPxContextCommand
//--------------------------------------------------------------
{
// -----------------
// Konstruktion/ Destruktion
public:
// -----------------

    interactiveValueTweakCtxCommand() {};
    ~interactiveValueTweakCtxCommand() {};


// ------------------------------------
// Überladene, redefinierte Methoden
public:
// ---------------------------------------

	/*
	virtual	MStatus		doEditFlags();
	virtual MStatus		doQueryFlags();
	virtual MStatus		appendSyntax();
	*/

	virtual MPxContext * makeObj();

public:
    static void* creator();



// ------------------------------------
// Private Variablen
private:
// ------------------------------------

	interactiveValueTweakCtx* context;
};



#endif // !defined(AFX_SOFTTRANSFORMATIONTOOL_H__6F784EDA_4CE2_46D0_A479_212171CAB53C__INCLUDED_)

