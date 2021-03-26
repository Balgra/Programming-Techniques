#include <stdio.h>
#include <stdlib.h>
void GuessNr(int nrtoguess)
{
    int guess; 
    
    do {
        scanf("%d", &guess);
        if (guess == nrtoguess)
         {
            printf("You guessed correctly,nice job \n");
            exit(-1);
        }

        if (guess < nrtoguess)
         {
            printf("Your guess is too low. Guess again. ");
        }

        if (guess > nrtoguess)
         { 
            printf("Your guess is too high. Guess again. ");
        }
    } while (1);

}
int main() {
    int nrtoguess =80;
    printf("I'm thinking of a number bettween 0 and 1000, guess my number! "); 
    GuessNr(nrtoguess);
}