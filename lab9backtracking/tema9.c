/*
problema1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define Mazelenght 6

char InitialMaze[10][10];

int endi=2,endj=3;

int MazeRunner(int i,int j)
{

	if(InitialMaze[i][j]=='1')
	{
		InitialMaze[i][j]='x';
		printf("%d %d to ",i,j);
	  if(i==endi && j==endj)
		{
			printf("the matrix:\n");

			for(i=0;i<Mazelenght;i++)
				{
					for(j=0;j<Mazelenght;j++)
						{
							printf("%c",InitialMaze[i][j]);
						} 

					printf("\n");
				}
				exit(-1);
		}
		if(i-1>0)MazeRunner(i-1,j);
		if(i+1<4)MazeRunner(i+1,j);
		if(j-1>0)MazeRunner(i,j-1);
		if(j+1<4)MazeRunner(i,j+1);

		InitialMaze[i][j]='1';
	}

	return 0;

}

int main()
{
	int i=0,j;

	char s[10];

	FILE *fin;

	fin=fopen("tema9.txt","r");

	if(fin!=NULL)
	{
		while(fgets(s,10,fin)!=NULL)
		{
			for( j=0;j<strlen(s);j++)
			{
					InitialMaze[i][j]=s[j];
			}
			i++;
		}
	}

	printf("From:");

	MazeRunner(0,0);

	printf("the matrix: \n");



}*/


//problema 3;

#include<stdio.h>
#include<stdlib.h>

#define N 8

int ChessBoard[N][N];
int nrofsolution=1;


int Verifypositions(int row, int col) 
{ 
    int i, j; 
  
    for (i = 0; i < col; i++) 
    {
        if (ChessBoard[row][i]) 
        {
            return 0; 
        }
    }
  
    for (i=row, j=col; i>=0 && j>=0; i--, j--) 
    {
        if (ChessBoard[i][j]) 
        {
            return 0; 
        }
    }
  
    for (i=row, j=col; j>=0 && i<N; i++, j--) 
    {
        if (ChessBoard[i][j]) 
        {
            return 0; 
        }
    }
  
    return 1; 
} 
 
int QueensProblem(int col) 
{ 
    if (col == N) 
    { 
         printf("This is the %d solution \n",nrofsolution++); 
   		 for (int i = 0; i < N; i++) 
    	{ 
        	for (int j = 0; j < N; j++) 
        	{
            	printf(" %d ", ChessBoard[i][j]); 
            }
       		 printf("\n"); 
    	} 
    	printf("\n"); 

        return 1; 
    } 

    int result = 0; 
    for (int i = 0; i < N; i++) 
    { 
        if ( Verifypositions(i, col) ) 
        { 
            ChessBoard[i][col] = 1; 
  
            result = QueensProblem(col + 1);

            ChessBoard[i][col] = 0;
        } 
    } 
  
    return result; 
} 


int main() 
{ 

	QueensProblem(0);

    return 0; 
}