
#include <iostream>
#include <vector>

#include "d_util.h"
#include "d_random.h"

using namespace std;


template<typename T>
void join(vector<T> &vA,const vector<T>& vB);


int main()
{
    vector<int> vSmall,vLarge,vMedium;
    randomNumber rnd;

    int i,value;
    for(i =0; i < 12; i++)
    {
	value = rnd.random1(900) + 100;
	if(value < 400)
	    vSmall.push_back(value);
	else if(value < 700)
	    vMedium.push_back(value);
	else
	    vLarge.push_back(value);
    }
cout<<endl;
    insertionSort(vSmall);
    cout << "Small...";
    writeVector(vSmall);

    insertionSort(vMedium);
    cout << "Medium: ..";
    writeVector(vMedium);

    insertionSort(vLarge);
    cout << "Large...";
    writeVector(vLarge);

    join(vSmall,vMedium);
    join(vSmall,vLarge);

    cout<<"Sorted.";
    writeVector(vSmall);

    return 0;
}
