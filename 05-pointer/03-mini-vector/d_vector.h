template<typename T>
class miniVector
{
public:
    miniVector(int size = 0);

    //copy 
    miniVector(const miniVector<T>& obj);
    ~miniVector();
    //assign
    miniVector& operator=(const miniVector<T>& rhs);

    T& back();
    const T& back() const;

    T& operator[](int i);

    const T& operator[](int i)const;

    void push_back(const T& item);
    void pop_back();
    int size() const;
    bool empty() const;
    int capacity() const;

private:
    int vapacity;
    int vSize;
    T vArr[];
    void reserve(int n,bool copy);
};

template<typename T>
void miniVector<T>::reserve(int n,bool copy) 
{
    T  *newArr;
    int i;

    newArr = new T[n];
    if(newArr == NULL)
	throw memoryAllocationError(
	    "miniVector reserve() ; memory allocation failure");

    if(copy)
	for(i = 0; i < vSize; i++)
	    newArr[i]= vArr[i];
    if(vArr != NULL)
	delete []vArr;

    vCapacity = n;
    vArr = newArr;
}

template<typename T>
miniVector<T>::miniVector(int size):vSize(0),vCapacity(0),vArr(NULL)
{
    int i;
    if(size == 0)
	return;

    reserve(size,false);
    reserve(size,false);

    vSize = size;
    for(i =0; i < vSize; i++)
	vArr[i] = T();
}

template<typename T>
miniVector<T>::~miniVector()
{
    if(vArr  != NULL)
	delete  []vArr;

}


template<typename T>
miniVector<T> &  miniVector<T>::operator=(const miniVector<T> &rhs)
{
    int i;
    if(vCapacity < rhs.vSize)
	reserve(rhs.vSize,false);

    vSize = rhs.vSize;
    for(i = 0; i < vSize; i++)
	vArr[i] = rhs.vArr[i];

    return *this;

}

template<typename T>
void miniVector<T>::push_back(const T& item)
{
    if(vSize == vCapacity)
    {
	if(vCapacity == 0
	    reserve(1,false);
	else
	    reserve(2 * vCapacity , true);

    }
    vArr[vSize] = item;

    vSize++;
}

template<typename T>
void miniVector<T>::pop_back()
{
    if(vSize == 0)
	throw underflowError("miniVecotr pop back(): vector is empty");

    vSize--;
}

template<typename T>
T& miniVector<T>::back()
{
    if(vSize == 0)
	throw underflowError("miniVecotr back() : vector is empty");
    return vArr[vSize-1];
}

template<typename T>
T& miniVector<T>::operator[](int i)
{
    if(i < 0 || i >= vSize)
	throw underflowError("index range error");

    return vArr[i];
}


