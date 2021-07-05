#include <list>
using namespace std;


int seqSearch(const int arr[],int first , int last ,int target)
{
    int i = first;
    while( i != last && arr[i] != target)
	i++;

    return i;
}

template<typename T>
list<T>::iterator seqSearch2(list<T>::iterator first,list<T>::iterator last,const T& target)
{
    auto iter = first;
    while(iter != last && (*iter != target)) iter++;
    return iter;

}


int binsearch(const int arr[],int first ,int last ,int target)
{
    int mid;
    int midValue;

    int origLast = last;
    while(first  < last){
	mid = (first + last) /2;
	midValue = arr[mid];
	if(target == midValue)
	    return mid;
	else if(target  < midValue)
	    last = mid;
	else 
	    first = mid + 1;
    }
    return origLast;
}
