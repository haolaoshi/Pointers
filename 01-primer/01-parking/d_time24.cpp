#include <iostream>
#include "d_time24.h"

using namespace std;

time24::time24(int h,int m):hour(h),minute(m)
{
    normalizeTime();
}

void time24::normalizeTime()
{
    int extraHours = minute / 60;
    minute %= 60;
    hour = (hour + extraHours ) % 24;
}

time24 time24::duration(const time24& t)
{
    int currTime = hour * 60 + minute;
    int tTime = t.hour * 60 + t.minute;
    
    if(tTime < currTime){
	printf("time24 duration():argument is an earlier time");
	exit(1);
    }else
	return time24(0,tTime - currTime);
}

void time24::readTime()
{
    char delimiter;
    cin >> hour >> delimiter >> minute;
    normalizeTime();
}
int time24::getHour() const 
{
    return hour;
}

int time24::getMinute()const
{
    return minute;
}

void time24::writeTime() const
{
    if(hour < 10) cout <<"0"; 
    cout << hour << ":";
    if(minute < 10) cout <<"0";
    cout <<minute;
}

