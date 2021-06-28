#include <iostream>
#include <cstdlib>
#include "d_sort.h"

using namespace std;


int main()
{
    int arr[15];
    int i;
    cout <<"Generate Array:"<<endl;   
   for(i = 0; i < 15; i++){
	arr[i] = rand() % 100 + 1;
	cout << arr[i] << " ";
    }
    cout << endl;
    selectionSort(arr,15);
    cout << "Sorted array"<< endl;

    for(i = 0; i < 15; i++)
	cout << arr[i] << " ";
    cout << endl;

    exit(0);
}
