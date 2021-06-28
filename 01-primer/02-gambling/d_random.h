#include <time.h>
#include <stdlib.h>
#include <stdio.h>

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

