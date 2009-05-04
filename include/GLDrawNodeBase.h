// GLDrawNode.h: interface for the header class.
//
//////////////////////////////////////////////////////////////////////

#ifndef GLDRAWNODEBASE_H
#define GLDRAWNODEBASE_H



// -----------------
//	Maya Includes
// -----------------

#include <maya/M3dView.h>

// -----------------
//	Eigene Includes
// -----------------

// -----------------
//	Diverse Includes
// -----------------




// Diese Node enth�lt alles was man braucht, um mit openGl zu zeichnen
//
#include <GL/glu.h>


namespace BPT
{


/* *	Ne v�llige Unsinnsklasse: Diese Base wird von den Globals included, w�hrend sich die GLDRAWNODE die Globals holt
*/

//#################################################
//-------------------------------------------------
//	KLASSENBESCHREIBUNG
	class GLDrawNodeBase
//-------------------------------------------------
//#################################################
{

//------------------------------
// Konstruktion/Destruktion - nur standard
public:
//------------------------------
	

	

//------------------------------
// Methoden
public:
//------------------------------

	/* * Zeichnet die abgeleitete Klasse

	*/
	virtual void	draw( M3dView& view) = 0;



};

}

#endif 
