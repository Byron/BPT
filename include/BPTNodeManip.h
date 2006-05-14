
#ifndef BPTNODEMANIP_H
#define BPTNODEMANIP_H



// -----------------
//	Maya Includes
// -----------------



#include <maya/MPxLocatorNode.h>
#include <maya/MString.h> 
#include <maya/MTypeId.h> 
#include <maya/MPlug.h>
#include <maya/MDataHandle.h>


// -----------------
//	Eigene Includes
// -----------------
 
#include <MACROS.h>
#include <BGlobals.h>
#include <MP_geometry.h>




namespace BPT
{

/* Dieser Manipulator stellt ein Interface dar zur BPTNode.

  @remarks
	Er enthält seinerseits wiederum einen entsprechenden manipulator, der hardcoded ist.
	Dieser Manip ist managed - er wird also verwaltet vom eigenen ManipCreation/Destruction System

  @sa MP_automated

*/

// **********************************************************
class ByronsPolyToolsNodeManip : public		MPxLocatorNode
// **********************************************************
{

//--------------------
//MPXNODE METHODEN
public:
//--------------------

	ByronsPolyToolsNodeManip(){};
	virtual					~ByronsPolyToolsNodeManip(){}; 

	/** Die Compute Method wird eigentlich nicht benötigt, allerdings lasse ich sie erstmal stehen, 
		für den Fall dass sie mal nützlich werden sollte.
	*/
   // virtual MStatus   		compute( const MPlug& plug, MDataBlock& data );

	/** Zeichnet den Manipulator
	*/
	virtual void            draw( M3dView & view, const MDagPath & path, 
								  M3dView::DisplayStyle style,
								  M3dView::DisplayStatus status );



	static  void *		    creator();
	static  MStatus         initialize();


//--------------------
//MANIPULATOR KEY METHODEN
public:
//--------------------
	
	virtual MStatus createChildren();
    virtual MStatus connectToDependNode(const MObject & node);


	// ----------
	// ATTRIBUTES
	// ----------


	static	MTypeId			id;


//--------------------
//PRIVATE METHODEN
private:
//--------------------



//--------------------
// MANIPULATOR DATA
private:
//--------------------




};

} // namespace BPT ende

#endif	// BPTNODEMANIP_H
