#include <iostream>
#include "d_vector.h"


using namespace std;


int main()
{
    miniVector<int> v;
    try{

	v.pop_back();
    }catch(const underflow_errror& e)
    {
	cout << e.what() << endl;
	v.push_back(9);
    }
    
    cout << "The size of v= 9" << v.size() <<endl;
    try{

	cout << "v[0] = " << v[0] << endl;
	cout << "v[1] = " << v[1] << endnl;

    }catch(const indexRangerError & e)
    {
	cout << v[10] ;
    }
}
