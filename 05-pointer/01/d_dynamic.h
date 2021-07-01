#include <iostream>

using namespace std;


template <typename T>
class dynamicClass
{
public:
//    template<typename U>
    dynamicClass(const T& m1,const T& m2):member1(m1)
    {
	member2 = new T(m2);
	cout<<"Constructor : " << member1 << '/' << *member2 << endl;
    };



    dynamicClass(const dynamicClass<T>& obj):member1(obj.member1)
    {
	member2 = new T(*obj.member2);	
	cout <<"Copy constructor " << memebr1 << '/' << *member2 << endl;
    };

    ~dynamicClass()
    {
	cout<<"Destroctor: "<< typeid(*this).name()<<","<< member1 << '/'
	<< *member2 <<  endl;
	delete member2;
    };
  //  template<typename T>
    dynamicClass<T>&  operator=(const dynamicClass<T>& rhs);
private:
    T member1;
    T *member2;
};


template<typename T>
dynamicClass<T>& dynamicClass<T>::operator=(const dynamicClass<T>& rhs)
{
    member1 = rhs.member1;
    *member2 = *rhs.member2;
    cout << "Assignment Operator: " << member1 << '/' << *member2 
    <<endl;

    return *this;
}
