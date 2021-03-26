#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int table[3][3];

void initMatrice()
{
   printf("initializarea  merge \n");
}

void printtable()
{
	printf("the table is, now fill it with 'X' and '0' \n");
    printf("|  |  |  |\n");
    printf("|  |  |  |\n");
    printf("|  |  |  |\n");

}

int verifyPosition(int x, int y)
{
    printf("verifyPosition  merge \n");

    return 0;
}

void verifyMatrix() 
{
    printf("verificarea Matricei merge \n");
}

void movePlayer1()
{
    printf("movePlayer1 merge \n");
}

int randomNumberGenerator(const int nMin, const int nMax, const int  nNumOfNumsToGenerate)
{
    printf("randomNumberGenerator merge \n");

    return 0;
}

void movePlayer2() 
{
    printf("movePlayer2 merge \n");
}   

int main()
{
    int isRunning = 1;
    printf("%d", isRunning);
    while(isRunning) {
        movePlayer1();
        movePlayer2();
        randomNumberGenerator(0, 3, 1);
        verifyMatrix();
        verifyPosition(0, 1);
        printtable();
        initMatrice();
        exit(-1);
    }
}