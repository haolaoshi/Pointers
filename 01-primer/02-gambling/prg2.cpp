#include <iostream>
#include "d_random.h"


using namespace std;

int main()
{
    randomNumber die;
    int initToss,nextToss;

    initToss = (1 + die.random(6)) + (1 + die.random(6));

    if(initToss == 2|| initToss == 3 || initToss == 12)
	cout<<"Initial toss is " << initToss << " House wins " << endl;
    else if(initToss == 7 || initToss == 11)
	cout << "Initial toss is " << initToss << " Player wins " << endl;
    else{
	cout << "Target is "<< initToss << " Play on" << endl;
	do 
	{
	    nextToss = (1 + die.random(6)) + ( 1 + die.random(6));
	    cout << "Next toss " << nextToss << endl;

	}while(nextToss != 7 && nextToss != initToss);
	if(nextToss == 7 )
	    cout << "  Craps - HOurse winds " << endl;
	else
	    cout << "  Match - player winds " <<endl;
    }
    return 0;
}
