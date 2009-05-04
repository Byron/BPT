// GLDrawNode.h: interface for the header class.
//
//////////////////////////////////////////////////////////////////////

#ifndef GLDRAWNODE_H
#define GLDRAWNODE_H



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
#include <GLDrawNodeBase.h>



// Diese Node enthält alles was man braucht, um mit openGl zu zeichnen
//
#include <GL/glu.h>


namespace BPT
{


/* *	Hierbei handelt es sich um eine abstrakte Klasse, welche sich bei Byronimo ( dem Verteiler für drawEvents )
		registriert.

		@remarks
			So wird es einer normalen dependNode ermöglicht, in den viewPort zu zeichnen.
			All dies geschieht intern, so dass keine Fehlerträchtigen connections gemacht werden müssen
*/

//#################################################
//-------------------------------------------------
//	KLASSENBESCHREIBUNG
	class GLDrawNode	: public GLDrawNodeBase
//-------------------------------------------------
//#################################################
{

//------------------------------
// Konstruktion/Destruktion
public:
//------------------------------
	
	/** Registriert sich bei den BGlobals mit seinem Pointer, so dass von dort aus dann drawCommands über
		den Pointer an die abgeleitete Klasse gesendet werden können.
	*/
	GLDrawNode(){
					// BGlobals::drawNodeQueue.insert(this);
				};


	/** Deregistriert sich bei den BGlobals
	*/
	~GLDrawNode(){
					// BGlobals::drawNodeQueue.erase(this);
				};
	

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
