// dData.h: interface for the dData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DDATA_H__1E5256C7_ACA4_4FD9_A34F_C62C888EC881__INCLUDED_)
#define AFX_DDATA_H__1E5256C7_ACA4_4FD9_A34F_C62C888EC881__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <MACROS.h>

namespace BPT
{

/** Einfache KapselKlasse, welche directionalData beinhaltet. Genutzt von der face Klasse

*/

class dData  
{
public:
	dData();
	dData(int startLoc,int endLoc, int cStartLoc,int cEndLoc,int startAbs,int endAbs,int cStartAbs,int cEndAbs,int type,int requester,int inNachbarID);
	virtual ~dData();

	//reine ContainerKlasse, enth�lt nur einige Variablen

	int	startLocID;
	int	endLocID;
	
	int startLocCorner;
	int endLocCorner;
	
	int startAbsID;
	int endAbsID;
	
	int startAbsCorner;
	int	endAbsCorner;
	
	int typeInfo;	//enth�lt den Typ des originalRequesters, so dass DirectionControl Nodes entscheiden k�nnen, wie sie sich verhalten
	int	nachbarID;	//enth�lt die LocID des nachbarn, welcher um ne direction gefragt werden k�nnte. Wenn convertData/ToOpposite aufgerufen, ver�ndern sie diesen Wert entsprechend
					//nachbarID sollte lokaler Wert sein (ob das �berhaupt ben�tit wird ? JA - wenn mehrere Nachbarn pro CornerEdge)
	int requesterID;	//ist die ID des urspr�nglichen Auftraggebers: in Loops muss dieser Vergleich daf�r sorgen, dass Schleifen unm�glich werden
					//und ist absID
	bool isFlipped;

};

}

#endif // !defined(AFX_DDATA_H__1E5256C7_ACA4_4FD9_A34F_C62C888EC881__INCLUDED_)
