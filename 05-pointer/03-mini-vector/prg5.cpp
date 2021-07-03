#include <iostream>
#include "d_vector.h"
#include <stdexcept>
#include <string>

using namespace std;

void test1(){
    miniVector<int> v;
    miniVector<string> vStr(1);
    int i;
    cout << v.size() << " , " << vStr.size() << endl;

    for(i = 0; i < 5; i++)
	v.push_back(i);

    cout << v.size() << ", " << v.capacity() << endl;
    vStr[0] = "mini";
    vStr.push_back("meou");
    cout << vStr.size() << "," << vStr.capacity() << endl;
}

int main()
{
    miniVector<int> v;
    try{
	v.pop_back();
    }catch(const underflow_error& e)
    {
	cout <<"Catch Eerror:" << e.what() << endl;
	v.push_back(9);
    }
    
    cout << "The size of v: " << v.size() <<endl;
    try{
	cout << "v[0] = " << v[0] << endl;
	cout << "v[1] = " << v[1] << endl;

    //}catch(const range_error& e)
    }catch(const underflow_error& e)
    {
	cout <<endl<<"Catch Eerror:" << e.what() << endl;
    }
    return 0;
}    

