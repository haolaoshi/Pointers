/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main ()
{
  int iSecret, iGuess;

  /* initialize random seed: */

    srand (time(NULL));
  /* generate secret number between 1 and 10: */

   for(int i = 0 ; i < 10; i++){
      printf("%d,",(rand()%10+1));
    }
    return 0;
}
