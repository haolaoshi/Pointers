#include <stdio.h>


int main()
{
    int p;//a variable
    int *p;// p; *p;    int *p;
    int p[3];// p[] is array;  int p[] ;
    int *p[3];//p[] is array;  in elements is int *;

    int (*p)[3];//*p is a pointer;  (*p)[3] ,this pointer to array;inwhich element is int;

    int **p;// p is pointer to pointer, in;t

    char a[20] = "You_are_a_good_man!!";
    char *p = a;
    char **ptr = &p;

    printf("p=%p,this is a pointer(address)\n",p);
    printf("ptr=%p,this is a pointer to char*,a[0] , a char\n",ptr);

    printf("*ptr=%p, \n",*ptr);
    printf("**ptr = %c\n",**ptr);
}
