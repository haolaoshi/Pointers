
void selectionSort(int arr[],int n)
{

    int smallIndex;
    int pass , j;
    int temp;


    for(pass = 0; pass < n - 1; pass++)
    {
	smallIndex = pass;
	for( j = pass + 1; j < n; j++)
	    if(arr[j] < arr[smallIndex])
		smallIndex = j;
	if(smallIndex != pass)
	{
	    temp = arr[pass];
	    arr[pass] = arr[smallIndex];
	    arr[smallIndex] = temp;

	}
    }
}
