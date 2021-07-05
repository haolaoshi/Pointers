#include <iostream>

#include <string>
#include <list>
#include <ctype.h>


using namespace std;

template<typename T>
bool isPalindrome(const list<T>& alist);

int main()
{
    string str;
    list<char> charList;
    int i;
    char ch;

    cout << "Enter the string: " ;
    getline(cin,str,'\n');


    for(i = 0; i < str.length(); i++)
    {
	ch = str[i];
	if(isalpha(ch))
	    charList.push_back(tolower(ch));

    }

    if(isPalindrome(charList))
	cout << " ' " << str << " ' is a palindrome . " << endl;
    else
	cout << " ' " << str << " ' is not a palidrom . " << endl;
	
    return 0;
}

template<typename T>
bool isPalindrome(const list<T>& alist)
{
    list<T> copyList;
    copyList = alist;

    while(copyList.size() > 1)
    {
	if(copyList.front() != copyList.back())
	    return false;

	copyList.pop_front();
	copyList.pop_back();
    }

    return true;
}
