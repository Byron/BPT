#include <timer.h>


//-----------------------------
timer::timer(const string& message)			
//-----------------------------
{
	messageStr = message;
	
	#ifdef WIN32

	/*
	cout<<endl<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"... Beginne Zeitmessung ... "<<endl;
	cout<<message.asChar()<<endl;
	cout<<"----------------------------"<<endl<<endl;
	*/

	//Frequenz holen, um in sekunden umzurechnen
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&start);

	//cout<<"STARTZEIT: "<< ( (double)start.QuadPart / (double)freq.QuadPart) <<endl;
	#else
	gettimeofday(&startTime, NULL);
	#endif 
}

//-----------------------------
timer::~timer(void)
//-----------------------------
{
	#ifdef WIN32
	
	_LARGE_INTEGER end;
	QueryPerformanceCounter(&end);
	double elapsedTime = ((double)end.QuadPart - (double)start.QuadPart) / (double)freq.QuadPart
	
	#else

	struct timeval now;
    gettimeofday(&now, NULL);
	unsigned long elapsedTime =
		(now.tv_sec - startTime.tv_sec) * 1000 + ( now.tv_usec - startTime.tv_usec ) / 1000;
	#endif
	
	cout << endl;	
	cout << messageStr.data() << endl;
	cout << "ELAPSED TIME: "<< elapsedTime << endl;
	cout << "------------------------------" << endl;
}

