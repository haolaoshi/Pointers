#include <iostream>
#include <fstream>
#include <list>
#include <cstdlib>
#include <string>
#include "d_wordfreq.h"
#include "d_search.h"
#include "d_util.h"

using namespace std;


int main()
{
    ifstream fin;
    list<wordFreq> wf;
    list<wordFreq>::iterator iter;

    string fileName,word;
    cout << "Enter name of the file containing the words:";
    cin >> fileName;

    fin.open(fileName.c_str());
    if(!fin)
    {
	cerr<<"cannot open " << fileName << endl;
	exit(1);
    }
    while(fin >> word)
    {
	wordFreq obj(word);
//int seqSearch(const int arr[],int first , int last ,int target)
	//iter = seqSearch<wordFreq>(wf.begin(),wf.end(),obj);
	iter = seqSearch2<wordFreq>(wf.begin(),wf.end(),obj);
	if(iter != wf.end())
	    (*iter).increment();
	else
	    wf.push_back(obj);
    }
    wf.sort();
    cout<<endl;
    writeList(wf,"\n");
    return 0;
}
