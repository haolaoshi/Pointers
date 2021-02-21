#include <stdio.h>

int array[] = {23,24,12,17,204,99,16};
#define TOTAL   (sizeof(array)/sizeof(array[0]))
foo(const char  **p){}

main(int argc, char **argv)
{
//    foo(argv);
    const int a = 0;
    const int *b = &a;
    //*b += 1;
    int j = 2;
    b = &j;

    //printf("%d\n",*b);
   if( -1 < (unsigned char)1)
        printf("-1 is less than (unsigned char)1: ANSI sematics.\n");
   else 
        printf("-1 is NOT less than (unsigned char)1: K&R sematics.\n");

    int d = -1,x;
    if(d <= (int)TOTAL - 2)
        x = array[d + 1];

    printf("x = %d, real = %d\n",x,array[0]);
}
