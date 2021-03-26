#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int isRunning = 1;
int table[3][3];
int length=0;

void printtable()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(table[i][j]==0)
            {
                table[i][j]=32;
            }
        }
    }

    printf("| %c | %c | %c |\n", (char)table[0][0], (char)table[0][1], (char)table[0][2]);
    printf("| %c | %c | %c |\n", (char)table[1][0], (char)table[1][1], (char)table[1][2]);
    printf("| %c | %c | %c |\n", (char)table[2][0], (char)table[2][1], (char)table[2][2]);
    length++;
     if(length==10)
        {
            printf("it's a draw \n");
            exit(-1);
        }
}

int verifyPosition(int x, int y) {

    if(table[x][y] == 32) return 1;
    else return 0;
}

int verifyMatrix() {

    int i;
    for(i = 0; i < 3; i++) {
        if((table[i][0] == table[i][1] && table[i][0] == table[i][2]) && table[i][0] != 32)
            return 1;
    }
    for(i = 0; i < 3; i++) 
    {
        if((table[0][i] == table[1][i] && table[0][i] == table[2][i]) && table[0][i] != 32)
            return 1;
    }

    if((table[0][0] == table[1][1] && table[0][0] == table[2][2]) && table[0][0] != 32) 
        {
            return 1;
        }
    if((table[0][2] == table[1][1] && table[0][2] == table[2][0]) && table[0][2] != 32)
         {
            return 1;
         }
    return 0;
}

void movePlayer1() 
{
    int x, y;
    printf("\n");
    printf("Jucatorul 1 trebuie sa introduca urmatoarea mutare alege 2 numere intre 1 si 3\n");
    printf("X = linia si Y = coloana introdusa\n");
    scanf("%d %d", &x, &y);
    printf("Ai introdus x = %d si y = %d\n", x, y);
    if((x > 0 && x <= 3) && (y > 0 && y <= 3)) 
    {
        if(verifyPosition(x - 1, y - 1)) 
        {
            table[x - 1][y - 1] = 88;
            if(verifyMatrix()) 
            {
                printf("Player-ul a castigat!!\n");
                printtable();
                exit(-1);
                isRunning = 0;
            }
             else 
            {
                printtable();
            }
        } 
        else 
        {
            printf("Pozitia este deja ocupata, introdu din nou datele");
            movePlayer1();
        }
    } 
    else 
    {
        printf("Datele introduse gresit, introdu din nou datele");
        movePlayer1();
    }
}

// the random function
int randomNumberGenerator(const int nMin, const int nMax, const int  nNumOfNumsToGenerate)
{
  int nRandonNumber = 0;
  for (int i = 0; i < nNumOfNumsToGenerate; i++)
  {
    nRandonNumber = rand()%(nMax-nMin) + nMin;
    //printf("%d ", nRandonNumber);
  }
  return nRandonNumber;
}

void movePlayer2() 
{
    int x = randomNumberGenerator(0, 3, 1);
    int y = randomNumberGenerator(0, 3, 1);
    while(!verifyPosition(x, y)) 
    {
        x = randomNumberGenerator(0, 3, 1);
        y = randomNumberGenerator(0, 3, 1);
    }
    printf("Playerul 2 a ales %d %d\n", x + 1, y + 1);
    table[x][y] = 48;
    if(verifyMatrix()) 
    {
        printf("Computerul a castigat!!\n");
        printtable();
        exit(-1);
        isRunning = 0;
    } 
    else 
    {
        printtable();
    }
}

int main()
{

    srand(time(NULL));
  //  printf("%d", isRunning);
    printtable();
    while(isRunning) 
    {
        movePlayer1();
        movePlayer2();
        if(length==8)
        {
            printf("it's a draw");
        }
    }
}