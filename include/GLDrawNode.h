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



// Diese Node enth�lt alles was man braucht, um mit openGl zu zeichnen
//
#include <GL/glu.h>


namespace BPT
{


/* *	Hierbei handelt es sich um eine abstrakte Klasse, welche sich bei Byronimo ( dem Verteiler f�r drawEvents )
		registriert.

		@remarks
			So wird es einer normalen dependNode erm�glicht, in den viewPort zu zeichnen.
			All dies geschieht intern, so dass keine Fehlertr�chtigen connections gemacht werden m�ssen
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
	
	/** Registriert sich bei den BGlobals mit seinem Pointer, so dass von dort aus dann drawCommands �ber
		den Pointer an die abgeleitete Klasse gesendet werden k�nnen.
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
