#include <iostream>
#include "d_search.h"
#include "d_sort.h"

using namespace std;



int main()
{
    int arr[15] = {29,-7,12,1,19,2,23,0,10,12,2,890,2,130,-2};
    int target , index;

    printArray(arr)    
    selectionSort(arr,15);
    printArray(arr)    
    cout << "Enter a integer target:"<<endl;
    cin >> target;

    index = binsearch(arr,0,15,target);
    if(index != 15)
	cout << target << " is in the list at index "<<index << endl;
    else 
	cout << target << " is not in the list . " << endl;

    exit(0);
}
