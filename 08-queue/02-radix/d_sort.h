#include <vector>
#include <queue>

using namespace std;


void distribute(const vector<int>&v ,queue<int>digitQueue[],int power)
{
    int i;
    for(i = 0; i < v.size(); i++)
	digitQueue[(v[i] / power ) % 10].push(v[i]);
}

void collect(queue<int> digitQueue[],vector<int>& v)
{
    int i = 0, digit;
    for(digit = 0; digit < 10; digit++)
	while(!digitQueue[digit].empty())
	{
	    v[i] = digitQueue[digit].front();
	    digitQueue[digit].pop();
	    i++;
	}
}

void randixSort(vector<int>& v,int d)
{
    int i;
    int power = 1;
    queue<int> digitQueue[10];
    for(i = 0; i < d; i++)
    {
	distribute(v,digitQueue,power);
	collect(digitQueue,v);
	power *= 10;
    }
}
