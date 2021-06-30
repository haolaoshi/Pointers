#include <iostream>
#include <ostream>

using namespace std;

template<typename T>
class store
{
public:
    store(const T& item = T());
    T getValue() const;
    void setValue(const T& item);
    template<typename U>
    friend ostream& operator<<(ostream& ostr,const store<U>& obj);
private:
    T value;
};

template<typename T>
void 
store<T>::setValue(const T& item)
{
    value = item;
}

template<typename T>
store<T>::store(const T& item):value(item){}


template<typename T>
T store<T>::getValue() const
{
    return value;
}

