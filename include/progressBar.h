
#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H


//INCLUDES
#include <maya/MString.h>
#include <maya/MGlobal.h>

#include <BMACROS.h>

namespace BPT
{

/** Diese Klasse erlaubt die Verwendung der MainMayaProgressBar auf bequeme art und weise

*/
class BYRONIMO_API progressBar
{

public:

	/** Konstruktor, der gleich einen Prozess startet
	*/
	// --------------------------------------------------
	progressBar( const MString& text, int maxCount);	
	// --------------------------------------------------

	/** Konstruktor, der gleich einen Prozess startet, allerdings mit StartCount
	*/
	// --------------------------------------------------
	progressBar( const MString& text, int startCount, int maxCount);	
	// --------------------------------------------------

	/** Konstruktor, der keinen Prozess startet
	*/
	// --------------------------------------------------
	progressBar( );	
	// --------------------------------------------------

	/** Bei der Destruktion werden alle laufenden Progressbars beendet
	*/
	// --------------------------------------------------
	~progressBar();
	// --------------------------------------------------

//-----------------------
//öffentliche Methoden
public:
//-----------------------

	/** Setzt den Progress auf den angegebenen Wert
	*/
	// --------------------------
	void set( int progress );
	// --------------------------

	/** Vergrößert den Progress um 1
	*/
	// ----------------
	void increment( );
	// ----------------

	/** Verkleinert den Progress um 1
	*/
	// ----------------
	void decrement( );
	// ----------------

	/** Startet die Progressbar neu
	*/
	// ----------------------------------------------------
	void begin( const MString& text, int startCount, int maxCount );
	// ----------------------------------------------------


	/** Beendet die Progressanzeige
	*/
	// ----------------
	void done( );
	// ----------------


//-----------------------
//private Variablen
private:
//-----------------------

	MString myText;
	int		startCount;
	int		maxCount;
	int		currentProgress;


};


}




#endif