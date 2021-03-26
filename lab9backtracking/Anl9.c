#include<stdio.h>

int answer=9999999;

void Travelling(int Travel[][20], int visited[], int currentPos, int n, int count, int kilometers) 
{ 

    if (count == n)
     { 
 
        if(answer > kilometers + Travel[currentPos][0])
        {
            answer=kilometers + Travel[currentPos][0];
        }
    } 

    for (int i = 0; i < n; i++)
     { 
        if ((visited[i]==0) && Travel[currentPos][i])
         { 

            visited[i] = 1; 

            Travelling(Travel, visited, i, n, count + 1, kilometers + Travel[currentPos][i]); 

            visited[i] = 0; 
        } 
    } 
}
  
 
int main() 
{ 


    int numTowns;
    printf("How many lines and collumns should the matrix have?\nRemember you give only one number because it is a symetric matrix of the Towns \n");
    scanf("%d",&numTowns);

    printf("After reading the number of the Towns give how many kilometers are between them,\nRemember the principal collumn should be 0 \n");

    int Travel[20][20];

    for(int i=0;i<numTowns;i++)
    {
        for(int j=0;j<numTowns;j++)
        {
            scanf("%d",&Travel[i][j]);
        }
    }
  
    int visited[100];
    for (int i = 0; i < numTowns; i++) 
        visited[i] = 0; 

    int firstpoz;
    printf("With which city would you like to start, give a number from 0 to %d \n",numTowns-1);
     scanf("%d",&firstpoz);

    visited[firstpoz] = 1; 
  
    Travelling(Travel, visited, firstpoz, numTowns, 1, 0); 
  
    printf("And the minimum length is from the first town and  back to it : %d \n",answer); 
  
    return 0; 
} 
