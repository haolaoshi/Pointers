#include <iostream>
#include <iomanip>
#include <vector>
#include "d_sort.h"
#include "d_random.h"

using namespace std;


void displayVector(const vector<int>& v);

int main()
{
    vector<int> intVector;
    randomNumber rnd;
    int i;

    for(i =0; i < 50; i++)
	intVector.push_back(rnd.random(100000));
    randixSort(intVector,5);
    displayVector(intVector);
    return 0;
}

void displayVector(const vector<int>& v)
{
    int i;
    for(i =0; i < v.size(); i++)
    {
	cout <<"\t" << v[i];
	if((i+1) % 6 == 0) 
	    cout << endl;
    }
    cout << endl;
}
