


template<typename T>
void selectionSort(T arr[],int n)
{
    int smallIndex;
    int pass, j;

    T temp;
    for(pass = 0; pass <  n - 1; pass++)
    {
	smallIndex = pass;
	for(j = pass + 1; j < n; j++)
	    if(arr[j] < arr[smallIndex])
		smallIndex = j;
	if(smallIndex != pass)
	{
	    temp = arr[pass];
	    arr[pass] = arr[smallIndex];
	    arr[smallIndex] =  temp;
	}
    }
}

template <typename T>
int seqSeach(const T arr[], int first ,int last ,const T& target)
{
    int i = first;
    while( i != last && arr[i]  != target)
	i++;

    return i;
}

template <typename T>
int binSearch(const T arr[],int first , int last ,const T& target)
{
    int mid;
    T midValue;
    int orignLast = last;
    while(first < last )
    {
	mid = (first + last)/2;
	midValue = arr[mid];
	if(target == midValue)
	    return mid;
	else if(target < midValue)
	    last = mid;
	else 
	    first = mid + 1;
    }
    return orignLast;
}
