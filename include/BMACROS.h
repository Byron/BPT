
//DIESE DATEI ENTHÃ„LT AUSSCHLIE?LICH MAKROS UND WIRD VON JEDER ANDEREN HEADER DATEI EINGEBUNDEN; DIE SIE BENÃ–TIGT

#ifndef BMACRO_FILE
#define BMACRO_FILE


// MATHE
//
#define	PI		3.14159265358979323846	/* pi */
#define	PI2		1.57079632679489661923	/* pi/2 */

// IOStream includes - ist absolut nötig
//
#include <iostream>
using std::cout;
using std::endl;


// PRAGMA DISABLES
// ----------------

#ifdef WIN32
#pragma warning( disable : 4010 )	// Die nervigen singleLine CommentWarnings ausschalten
#pragma warning( disable : 4786 )	// Die nervigen TemplateStringTruncation Warnings ausschalten
#pragma warning (disable : 4251 )	// Template BaseClass without dll interface - AUS
#pragma warning (disable : 4275 )	//"Diese variable braucht ein dll interface - nak nak " - AUS
#endif



// ------------------------
// Typedefs
// ------------------------


//*****************************
// GENERELLE DEFINES/ TYPEDEF
//*****************************

    typedef unsigned char uchar;
    typedef unsigned short ushort;
    typedef unsigned int uint;  
    typedef unsigned long ulong;


// ------------------------
// Namespaces
// ------------------------
namespace BPT{}

using namespace BPT;



#ifdef TIMER 
#include "timer.h"
#	define SPEED(message)	timer myTimer(message)
#	define NEWSPEED(message) timer* myTimer = new timer(message)
#	define DELETESPEED delete myTimer;
#else
#	define SPEED(message)
#	define NEWSPEED(message)
#	define DELETESPEED
#endif



#ifdef DEBUG
#	define BPRINT(message) cout<<message<<endl; 
#	define MPRINT(message) cout<<message<<endl; 
#	define BERROR(message) cout<<__FILE__<<" : "<<__LINE__<<": "<<message<<endl;
#	define INVIS(code) code
#	define MCheckStatus(status,message)			\
		if( MS::kSuccess != status ) {			\
			MString error("Status failed: ");	\
			error += message;					\
			MGlobal::displayError(error);		\
			return status;						\
		}
#else
#	define MPRINT(message)
#	define BPRINT(message)
#	define BERROR(message)
#	define INVIS(code)	
#	define MCheckStatus(status,message)	
#endif




//************************
//LINUX MODIFIKATIONEN
//************************

#ifndef WIN32
//das hier ist eigentlich ABSOLUTER UNFUG - wieso immer ULONG schreiben und es ersetzen lassen, wenn man auch gleich ulong verwenden kann..
//naja, so hat man immerhin maximale Kontrolle über das, was ULONG wirklich ist
	#define ULONG ulong		
	#define UINT uint
	#define UCHAR uchar

#endif



//*****************************
// DLL EXPORT DEFINITIONEN
//*****************************

#ifdef WIN32

#	define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#else

// Linux unterstützt exportSymbole nicht - da muss dann wohl ne def file verwendet werden
//
#	define BYRONIMO_API 



#endif


#endif // FILE
