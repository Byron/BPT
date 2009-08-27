#ifndef TIMER_INCLUDED
#define TIMER_INCLUDED

#include <MACROS.h>
#include <iostream>
#include <string>
#include <time.h>

#ifdef WIN32
#include "windows.h"
#else
#include <sys/time.h>
#endif 



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
class timer
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
	std::string messageStr;

#ifdef WIN32
	_LARGE_INTEGER start;
	_LARGE_INTEGER freq;	//frequenz des Counters
#else
	struct timeval startTime;
#endif // WIN32

	
};




#endif /*timer included*/
