#include <iostream>
#include "d_search.h"
#include "d_sort.h"
#include "d_random.h"

using namespace std;

int main()
{
    const int ARRAY_SIZE = 100000,TARGET_SIZE = 50000; 
    int list1[ARRAY_SIZE],list2[ARRAY_SIZE],targetList[TARGET_SIZE];
    int i;
    timer t;
    randomNumber rnd;

    for(i = 0; i < ARRAY_SIZE; i++)
	list1[i] = list2[i] =  rnd.random(1000000);

    for(i = 0; i < TARGET_SIZE; i++)
	targetList[i] = rnd.random(1000000);

    cout << "------>Timing Selection Sort<----------" << endl;

    t.start();
    selectionSort(list2,ARRAY_SIZE);
    t.stop();

    cout << "-----selection sort takes " << t.gettime() << " seconds."<<endl;

    cout << endl << "------>Timing begin SequnceSort<-------" << endl;
    t.start();
    for( i =0 ; i < TARGET_SIZE; i++)
	seqSearch(list1,0,ARRAY_SIZE,targetList[i]);
    t.stop();

    cout << "seq search takes " << t.gettime() << " seconds" << endl;

    cout << endl << "---------->Timing BinSearch<----------"<<endl;

    t.start();
    for(i =0; i < TARGET_SIZE; i++)
	binsearch(list2,0,ARRAY_SIZE,targetList[i]);

    t.stop();

    cout << "Binary seawrch takes : " << t.gettime() << " Seconds."<<endl;

    return 0;
}
