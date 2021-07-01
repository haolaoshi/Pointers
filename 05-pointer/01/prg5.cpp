#include <iostream>
#include "d_dynamic.h"


using namespace std;


void destroyDemo(int m1,int m2);

int main()
{
    dynamicClass<int> obj1(1,100);
    dynamicClass<int> *ptrObj2;
    ptrObj2 = new dynamicClass<int>(2,200) ;
    
    //ptrObj2 = &obj1;

    destroyDemo(3,300);
    delete ptrObj2;
    cout << "Ready to exit program." << endl;
    

    return 0;
}

void destroyDemo(int m1,int m2)
{
    dynamicClass<int> obj(m1,m2);
}
