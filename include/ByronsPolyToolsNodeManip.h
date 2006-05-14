// ByronsPolyToolsNodeManip.h: interface for the ByronsPolyToolsNodeManip class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(BYRONSPOLYTOOLSNODEMANIP)
#define BYRONSPOLYTOOLSNODEMANIP

#include <maya/MManipData.h>
#include <maya/MPxManipContainer.h>
#include <maya/MFnDirectionManip.h>
#include <maya/MFnDistanceManip.h>
#include <maya/MFnToggleManip.h>


#include <maya/MString.h> 
#include <maya/MTypeId.h> 
#include <maya/MPlug.h>
#include <maya/M3dView.h>
#include <maya/MFnNumericData.h>

#include <maya/MDagPath.h>
#include <maya/MVector.h>
#include <maya/MPoint.h>
#include <maya/MFnDagNode.h>
#include <maya/MFnTransform.h>
#include <maya/MFnDependencyNode.h>
#include <iostream>

using std::cout;
using std::endl;


class ByronsPolyToolsNodeManip  : public	MPxManipContainer
{
public:
	ByronsPolyToolsNodeManip();
	virtual ~ByronsPolyToolsNodeManip();


    static void * creator();
    static MStatus initialize();
    virtual MStatus createChildren();
    virtual MStatus connectToDependNode(const MObject & node);

    virtual void draw(M3dView & view, 
					  const MDagPath & path, 
					  M3dView::DisplayStyle style,
					  M3dView::DisplayStatus status);
	

	MManipData toggleSideCallbackToPlug(unsigned index) ;	//die *ToManip Methoden dienen der Umwandlung der Werte von Node zu Manip
	MManipData toggleAbsCallbackToPlug(unsigned index) ;	

	MManipData toggleSideCallback(unsigned index) const;	//wandelt int von side in Bool um
	//MManipData toggleAbsCallback(unsigned index) const;		//wandelt int von Absolute in Bool um
	
	MManipData toggleStartCallback(unsigned index) ;
	MManipData toggle2StartCallback(unsigned index) ;	//toggleStartCB's holen die Bildschirmpositionen und setzen sie als startPunkte

	MManipData directionCallback(unsigned index) ;
	MManipData directionCallbackToPlug(unsigned index) ;
	MManipData startPointCallback(unsigned index);
	//ManipData toggleDirectionCallback(unsigned index) const;	//soll normalSlidewert holen: wenn negativ, flippen  Toggle
	//Ich kann auch gleich direction+length() auf 0 setzen und die Position (startPoint) dann vom Screen holen, ev. auch ohne Flip	
	MManipData	slideOnlyCallbackToPlug(unsigned index);	//direktverbindung zum Slide
	


	MVector getCamTranslation() const;
	MPoint	getLeftScreenPoint();		//holt punkt von linker screenSeite;
	MPoint	getRightScreenPoint();	//holt Punkt von rechter ScreenSeite;
	MPoint	getCenterScreenPoint();


    MDagPath	fDirectionManip;
	MDagPath	fSideToggle;
	MDagPath	fAbsToggle;		//toggleManip für abs/relative Slide
	MDagPath	fSlideManip;


	MObject		fNode;
	MDagPath	camPath;		//cam vom View
	M3dView		myView;			//view selbst


public:
    static MTypeId id;
};

#endif // !defined(AFX_BYRONSPOLYTOOLSNODEMANIP_H__E74233D4_F095_4B12_B04F_5477520631E4__INCLUDED_)
