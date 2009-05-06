
#include <progressBar.h>


//CONSTRUCTION/DESTRUCTION

//----------------------------------------------------------------
progressBar::progressBar( )
: 
currentProgress(0)
//----------------------------------------------------------------
{}

//----------------------------------------------------------------
progressBar::progressBar(const MString& text, const int inMaxCount)
: 
myText(text), 
maxCount(inMaxCount),
startCount(0),
currentProgress(0)
//----------------------------------------------------------------
{
	begin( text, startCount, inMaxCount );
}


//----------------------------------------------------------------
progressBar::progressBar(const MString& text, int inStartCount, int inMaxCount)
: 
myText(text), 
maxCount(inMaxCount),
startCount(inStartCount),
currentProgress(0)
//----------------------------------------------------------------
{
	begin( text, startCount, inMaxCount );
}


//----------------------------------------------------------------
progressBar::~progressBar()
//----------------------------------------------------------------
{

	done();

}


//----------------------------------------------------------------
void progressBar::set( int progress )
//----------------------------------------------------------------
{
	
	currentProgress = progress;

	MString outStr(" global string 	$gMainProgressBar; 	progressBar -edit -pr "); 
	outStr += currentProgress;
	outStr += " -status \"";
	outStr += myText;
	outStr += " ( ";
	outStr += progress;
	outStr += " / ";
	outStr += maxCount;
	outStr += " ) \" $gMainProgressBar;";


	MGlobal::executeCommand(outStr, false, false); 

}



// ------------------------
void 
progressBar::increment( )
// ------------------------
{
	set( ++currentProgress );
}

// ----------------
void 
progressBar::decrement( )
// ----------------
{
	set( --currentProgress );
}


// ----------------------------------------------------
void 
progressBar::begin( const MString& text,int inStartCount, int inMaxCount )
// ----------------------------------------------------
{
	myText = text;
	maxCount = inMaxCount;
	startCount = inStartCount;
	currentProgress = inStartCount;
	
	MString outStr(" global string 	$gMainProgressBar; 	progressBar -edit -beginProgress -isInterruptable false	-status " + MString("\"") + myText + MString("\"") + " -maxValue " + maxCount + " -minValue " + startCount +  " $gMainProgressBar; ");
	MGlobal::executeCommand(outStr, false, false);
}


// ----------------
void 
progressBar::done( )
// ----------------
{
	MGlobal::executeCommand( (" global string 	$gMainProgressBar; 	progressBar -edit -ep $gMainProgressBar; "), false, false );
}
