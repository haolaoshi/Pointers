#include <iostream>
#include <queue>
#include <iomanip>
#include "d_time24.h"

using namespace std;

int main()
{
    time24 interviewTime;
    queue<time24> appq;
    cout << " First interview of the day: " ;
    cin >> interviewTime;

    while(interviewTime < time24(17,0))
    {
	appq.push(interviewTime);
	cout << " New interview Time: ";
	cint >> interviewTime;

    }

    cout << endl << "appoinement Available inerview Time " << endl;

    while(!appq.empty())
    {
	interviewTime = appq.front();
	cout << "  " << interviewTime << setw(17) << "  ";
	if(appq.empty())
	    cout <<  (time24(17,0) - interviewTime) << endl;
	else
	    cout << (appq.front() - interviewTime) << endl;

    }
    return 0;
}
