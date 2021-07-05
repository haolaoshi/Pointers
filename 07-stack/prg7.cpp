#include <iostream>
#include <stack>
#include <string>

using namespace std;

string multibase(int num,int b);

int main()
{
    int num ,b ;
    cout << "Eter a non-negative decimal number and abse"
	<< " (2 <=  <= 16) " << endl<< " or 0 0 to ternimate: " ;
    cin >> num >> b;

    while(b != 0)
    {
	cout << "  " << num << " base  " << b << " is " << multibase(num ,b) << endl;
	cout << "Enter a non-negative decimal number and base " 
	    << " (2 <= B <= 16) " << endl<<" or 0 0 to terminate";
	cin >> num >> b;
    }
    return 0;

}

string multibase(int num, int b)
{
    string digitChat = "0123456789ABCDEF",numStr = "";
    stack<char> stk;
    do
    {

	stk.push(digitChat[num % b]);
	num /= b;
    }while(num != 0);
    while(!stk.empty())
    {
	numStr += stk.top();
	stk.pop();
    }
    return numStr;
}
