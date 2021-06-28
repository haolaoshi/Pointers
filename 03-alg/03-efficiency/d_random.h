#include <stdlib.h>
#include <stdio.h>

#include <time.h>
class randomNumber{

public:
    randomNumber(int seed = 0):seed(seed){}
    
    int random(int n){
	srand(time(NULL));
	int d =  (rand() % n + 1);
	return d ; 
    }
private:
    int seed ; 
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
