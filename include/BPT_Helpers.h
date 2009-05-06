#ifndef BPT_HELPERS_INCLUDE
#define BPT_HELPERS_INCLUDE


#include <maya/MIntArray.h>
#include <maya/MString.h>
#include <maya/MVectorArray.h>
#include "BPT_BA.h"


//EINFACHE HELPER KLASSE ALS KAPSEL FÜR OFT VERWENDETE FUNKTIONEN

namespace BPT
{

/** Einfache KapselKlasse, welche hilfsmethoden beinhaltet und von vielen BPT Klassen verwendet wird

*/
class BPT_Helpers
{
public:
	BPT_Helpers(void);
	~BPT_Helpers(void);


public:	
	//METHODEN


void		sortArray(MIntArray& array) const;

bool		isOnArray(int valueToLookFor,const MIntArray& searchThisArray) const;

bool		getLocIndex(int value,const MIntArray& array, UINT& localIndex) const;
bool		getLocIndex(int value,const MIntArray& array, UINT& localIndex, int lowBound, int highBound) const;

bool		getLocIndexMod2(int value,const MIntArray& array, UINT& localIndex) const;
bool		getLocIndexMod2(int value,const MIntArray& array, UINT& localIndex, int lowBound, int highbBound) const;

bool		isOnArray(int value,const MIntArray& array, int lBound, int hBound) const;

void		addIntArrayToLHS(MIntArray& LHS,const MIntArray& RHS) const;

bool		UVSetDiffers(const MIntArray& UVs1, const MIntArray& UVs2) const;	//vergleicht die enthaltetenen UVs paarweise, und gibt true zurück, wenn sie sich unterscheiden

void		arrayRemove(MIntArray& lhs,MIntArray& rhs, bool affectLhsOnly = false);


ulong		genKey(const MString& string);


//	gibt IntArray mit IDs der doppelten Indices, OBSOLETE
MIntArray	pruneIntArray(MIntArray& orig, MIntArray& pruned);
//	Überladener PrundAlgorhytmus, der direkt auf array arbeitet

void		pruneIntArray(MIntArray& orig);

void		invertArray(MIntArray& array);

void		invertArray(MIntArray& array, int lBound, int rBound);


//---------------------
//SPEICHERLASTIGES
//---------------------

MIntArray	matchArray(	MIntArray lhs, 
						MIntArray rhs) const;

MIntArray	memoryMatch(MIntArray lhs, 
						MIntArray rhs);

void		memoryPrune(MIntArray& orig);

void		memoryPrune(MIntArray& orig, 
						MIntArray& doppelte);

void		memoryInvertSelection(MIntArray& lhs, 
								  int maxElement, 
								  MIntArray& inverted);

void		memoryArrayRemove(MIntArray& removeFrom,
							  const MIntArray& removals);

//DEBUG PROCS
//#ifdef DEBUG

	void		printArray(const MIntArray& array, MString message);

//#endif



///////////////////////
private: //VARIABLEN
	//////////////////


};


}

#endif
