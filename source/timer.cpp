#include <timer.h>

#ifdef WIN32

//-----------------------------
timer::timer(const string& message)			
//-----------------------------
{
	/*
	cout<<endl<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"... Beginne Zeitmessung ... "<<endl;
	cout<<message.asChar()<<endl;
	cout<<"----------------------------"<<endl<<endl;
	*/

	//Frequenz holen, um in sekunden umzurechnen
	QueryPerformanceFrequency(&freq);

	messageStr = message;
	

	QueryPerformanceCounter(&start);

	//cout<<"STARTZEIT: "<< ( (double)start.QuadPart / (double)freq.QuadPart) <<endl;
}

//-----------------------------
timer::~timer(void)
//-----------------------------
{
	_LARGE_INTEGER end;

	QueryPerformanceCounter(&end);

	cout<<endl;
	
	cout<<messageStr.data()<<endl;
	cout<<"VERGANGENE ZEIT: "<<((double)end.QuadPart - (double)start.QuadPart) / (double)freq.QuadPart<<endl;
	cout<<"------------------------------"<<endl;
}

#else

Linux Code


#endif