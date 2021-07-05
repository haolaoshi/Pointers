#include <vector>
#include <list>
#include <iostream>

using namespace std;

template<typename T>
void insertionSort(vector<T>& v)
{
    int i,j,n = v.size();
    T target;
    
    for(i = 1; i < n ; i++)
    {
	j = i;
	target = v[i];
	while(j > 0 && target < v[j-1])
	{
	    v[j] = v[j - 1];
	    j--;
	}
	v[j] = target;
    }
}

template<typename T>
void join(vector<T> &vA,const vector<T> &vB)
{
    int i , sizeB = vB.size();
    for(i = 0; i < sizeB; i++)
	vA.push_back(vB[i]);
}

template<typename T>
void writeVectorEnds(const vector<T>& v)
{
    if(v.size() > 0)
	cout << v[0] << " "<< v.back() << endl;
}

template<typename T>
void writeVector(const vector<T>& v)
{
    int i, n = v.size();
    for(i = 0; i < n ; i++)
	cout << v[i] << " ";
    cout <<endl;
}

template<typename T>
void writeList(const list<T>& alist, const string& separator = " ")
{
    for(auto iter = alist.begin(); iter != alist.end() ; iter++)
	cout<<(*iter)<<"  "; 
    cout <<endl;
}
