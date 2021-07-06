#include <stdlib.h>
#include <stdio.h>

#include <time.h>
class randomNumber{

public:
    
    randomNumber(int seed = 0):seeds(seed)
    {
	srand(time(NULL));
    }

    int random(int n){
	int d =  rand()%n  + 1;
	return d ; 
    }
private:
    int seeds ; 
};

class timer{

public:
    timer():t1(0),t2(0){}
    void start(){
	t1  = time(NULL);	
    }
    void stop()
    {
	t2 = time(NULL);	
    }

    int gettime()
    {
	return (t2 - t1);
    }
private:
    time_t  t1;
    time_t t2;
};
