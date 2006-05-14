// Copyright (C) 1997-2003 Alias|Wavefront, a division of Silicon Graphics Limited.
// 
// The information in this file is provided for the exclusive use of the
// licensees of Alias|Wavefront.  Such users have the right to use, modify,
// and incorporate this code into other products for purposes authorized
// by the Alias|Wavefront license agreement, without fee.
// 
// ALIAS|WAVEFRONT DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
// INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
// EVENT SHALL ALIAS|WAVEFRONT BE LIABLE FOR ANY SPECIAL, INDIRECT OR
// CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
// DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
// TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
// PERFORMANCE OF THIS SOFTWARE.

// $RCSfile: cvColorNode.cpp $     $Revision$

#include "BPTNodeManip.h"

// **********************
// STATISCHE VARIABLEN
// **********************


MTypeId     ByronsPolyToolsNodeManip::id( 0x34568 );

/*
//-----------------------------------------------------------------------
MStatus ByronsPolyToolsNodeManip::compute( const MPlug& plug, MDataBlock& data )
//-----------------------------------------------------------------------
{ 
	MStatus stat;

	cout<<"Compute gerufen für "<<plug.name()<<endl;

	data.inputValue(plug.attribute()).setClean();

	//return MS::kSuccess;
	return MS::kUnknownParameter;
}
*/

//-----------------------------------------------------------------------
void ByronsPolyToolsNodeManip::draw( M3dView & view, 
									 const MDagPath & path, 
									 M3dView::DisplayStyle style,
									 M3dView::DisplayStatus status )
//-----------------------------------------------------------------------
{ 
	
	view.drawText("!!!!!!!Test!!!!!!!!!!", MPoint());

}


//-----------------------------------------------------------------------
void* ByronsPolyToolsNodeManip::creator()
//-----------------------------------------------------------------------
{
	return new ByronsPolyToolsNodeManip();
}



//-----------------------------------------------------------------------
MStatus ByronsPolyToolsNodeManip::initialize()
//-----------------------------------------------------------------------
{ 
	// Hier noch die eigenen Parameter hinzufügen, wenn nötig


    MStatus stat;
  //  stat = MPxManipContainer::initialize();

	
	return stat;
}






//------------------------------------------------------------
MStatus ByronsPolyToolsNodeManip::createChildren()
//------------------------------------------------------------
{
	MStatus	stat;



	return	stat;
}

//-------------------------------------------------------------------------
MStatus	ByronsPolyToolsNodeManip::connectToDependNode(const	MObject& node)
//-------------------------------------------------------------------------
{
	MStatus	stat;	//ist default success
	

	return stat;
}
