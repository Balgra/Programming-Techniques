#include<stdlib.h>
#include<stdio.h>

int Chesstable[8][8];

int CoordinateX[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
int CoordinateY[8] = {  1, 2,  2,  1, -1, -2, -2, -1 }; 

int KnightSolution(int CoorknightX, int CoorknightY, int counter) 
{ 
   int line, collumn; 
   if (counter == 8*8 + 1)
   {
       return 1;
   }
   for (int i = 0; i < 8; i++)
   { 
       line =  CoorknightX + CoordinateX[i];
       collumn =  CoorknightY + CoordinateY[i];
       if (line >= 0 && collumn >= 0 && line < 8 && collumn < 8 && Chesstable[line][collumn] == 0) // if the solution is right i backtrack
       { 
            Chesstable[line][collumn] = counter;// i initialise it and backtrack
            if (KnightSolution(line, collumn, counter+1) == 1) // the recursive backtracking
            {
                return 1; 
            }
            else
            {
                Chesstable[line][collumn] = 0;// then i reverse it if the solution is not ok.
            }
       }
   }
   return 0;
}
int main()
{
    int firstX, firstY;

    printf("On which position should the knight start? give 2 number from 0 to 7,first for x position second for y position: \n");

    scanf(" %d %d", &firstX, &firstY);
    Chesstable[firstX][firstY]  = 1;
    KnightSolution(firstX, firstY, 2);
    for(int i=0; i<8 ; i++)
        {
          for(int j=0; j<8; j++)
           {
             printf("%d ", Chesstable[i][j]);
           }
            printf("\n");
        }
    
    return 0; 
} 
