#ifndef TIME24_H
#define TIME24_H
#include <iostream>

using namespace std;
class time24
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    time24();
    time24(int h,int m);
    time24(int h,int m,int s);
    friend bool operator<(time24 &a,time24 &b);
    friend bool operator>(time24 &a,time24 &b);
    friend ostream& operator<<(ostream &out,time24 &a);
    friend istream& operator>>(istream &in,time24 &a);
    int get_hours(){return hours;}
    int get_minutes(){return minutes;}
    int get_seconds(){return seconds;}
};

#endif 
