/****

>>>>>>friend declaration declares a non-template function<<<<<<<<
see:https://stackoverflow.com/questions/4660123/overloading-friend-operator-for-template-class


This is one of those frequently asked questions that have different approaches that are similar but not really the same. The three approaches differ in who you are declaring to be a friend of your function --and then on how you implement it.

The extrovert

Declare all instantiations of the template as friends. This is what you have accepted as answer, and also what most of the other answers propose. In this approach you are needlessly opening your particular instantiation D<T> by declaring friends all operator<< instantiations. That is, std::ostream& operator<<( std::ostream &, const D<int>& ) has access to all internals of D<double>.

template <typename T>
class Test {
   template <typename U>      // all instantiations of this template are my friends
   friend std::ostream& operator<<( std::ostream&, const Test<U>& );
};
template <typename T>
std::ostream& operator<<( std::ostream& o, const Test<T>& ) {
   // Can access all Test<int>, Test<double>... regardless of what T is
}

The introverts

Only declare a particular instantiation of the insertion operator as a friend. D<int> may like the insertion operator when applied to itself, but it does not want anything to do with std::ostream& operator<<( std::ostream&, const D<double>& ).

This can be done in two ways, the simple way being as @Emery Berger proposed, which is inlining the operator --which is also a good idea for other reasons:

template <typename T>
class Test {
   friend std::ostream& operator<<( std::ostream& o, const Test& t ) {
      // can access the enclosing Test. If T is int, it cannot access Test<double>
   }
};

In this first version, you are not creating a templated operator<<, but rather a non-templated function for each instantiation of the Test template. Again, the difference is subtle but this is basically equivalent to manually adding: std::ostream& operator<<( std::ostream&, const Test<int>& ) when you instantiate Test<int>, and another similar overload when you instantiate Test with double, or with any other type.

The third version is more cumbersome. Without inlining the code, and with the use of a template, you can declare a single instantiation of the template a friend of your class, without opening yourself to all other instantiations:

// Forward declare both templates:
template <typename T> class Test;
template <typename T> std::ostream& operator<<( std::ostream&, const Test<T>& );

// Declare the actual templates:
template <typename T>
class Test {
   friend std::ostream& operator<< <T>( std::ostream&, const Test<T>& );
};
// Implement the operator
template <typename T>
std::ostream& operator<<( std::ostream& o, const Test<T>& t ) {
   // Can only access Test<T> for the same T as is instantiating, that is:
   // if T is int, this template cannot access Test<double>, Test<char> ...
}

Taking advantage of the extrovert

The subtle difference between this third option and the first is in how much you are opening to other classes. An example of abuse in the extrovert version would be someone that wants to get access into your internals and does this:

namespace hacker {
   struct unique {}; // Create a new unique type to avoid breaking ODR
   template <>
   std::ostream& operator<< <unique>( std::ostream&, const Test<unique>& )
   {
      // if Test<T> is an extrovert, I can access and modify *any* Test<T>!!!
      // if Test<T> is an introvert, then I can only mess up with Test<unique>
      // which is just not so much fun...
   }
}






*/

#include <iostream>
#include <ostream>
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
    cout <<strStore<<endl;

    cout <<endl;

    cout << "The caoncatenation of 'Template' in strStore and "
    <<"'Class' is : " <<endl;
    strStore.setValue(strStore.getValue() + " Class");
    cout<<strStore<< endl;

    return 0;
}
// compile with: /EHsc

