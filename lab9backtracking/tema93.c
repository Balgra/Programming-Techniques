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