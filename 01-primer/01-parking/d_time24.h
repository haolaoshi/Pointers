#include <iostream>

using namespace std;

class time24
{
public:
    time24(int h=0,int m=0);
    void addTime(int m);
    time24 duration(const time24& t);
    void readTime();
    void writeTime() const;
    int getHour() const;
    int getMinute() const;
private:
    int hour;
    int minute;
    void normalizeTime();
};

