#ifndef TIMER_INCLUDED
#define TIMER_INCLUDED

#ifdef WIN32

#include <MACROS.h>

#include <time.h>

#include <string>

#include "windows.h"

#include <iostream>

using std::cout;
using std::endl;
using std::string;




/** Diese Klasse misst die Zeit vo Beginn ihrer Erzeugzung bis zur zerstörung und gibt dise aus
	
	Sie funktioniert nur unter win32, Momentan.

	@note
		Sie wird exportiert und so generell verfügbar gemacht.

	@todo
		Einen PerformanceManager bauen, welcher es ermöglicht, die Zeít zu messen, die in den einzelnen
		gemonitorten Prozeduren verbraucht wird.
*/

// -----------------------------
class BYRONIMO_API timer
// -----------------------------
{

// /////////////////////////////
//			Konstruktion	 //
public: //***************** //
// //////////////////////////

	timer(const string& message);			 
	~timer(void);


// ////////////////////////
//			Variablen   //
private: //*********** //
// /////////////////////

	_LARGE_INTEGER start;
	_LARGE_INTEGER freq;	//frequenz des Counters

	std::string messageStr;
};


#else

LINUX

#endif // WIN32


#endif /*timer included*/
