#include <iostream>
#include <string>
#include "d_store.h"

using namespace std;

template<typename T> 
ostream& operator<<(ostream& ostr,const store<T>& obj)
{
    ostr<<"Value = " << obj.value;
    return ostr;
}


int main()
{
    store<int> intStore(5);
    store<double> realStore(2.718);
    store<string> strStore("Template");

    cout <<"The values stored by the obj are:" << endl;
    cout<<intStore <<endl;
    cout<<realStore<<endl;
    cout << strStore<<endl;

    cout <<endl;

    cout << "The caoncatenation of 'Template' in strStore and "
    <<"'Class' is : " <<endl;
    strStore.setValue(strStore.getValue() + " Class");
    cout <<strStore<< endl;

    return 0;
}
