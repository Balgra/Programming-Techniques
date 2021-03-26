#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//divide et impera .

void Peakvalues(int vectors[], int first, int last)
{
    while (first < last)
    {
        int mid = (first + last) / 2;

        if ((vectors[mid - 1] <= vectors[mid] && vectors[mid] >= vectors[mid + 1]) || (vectors[mid - 1] >= vectors[mid] && vectors[mid] <= vectors[mid + 1]))
        {
            printf("%d ", vectors[mid]);

            Peakvalues(vectors,first,mid-1);

            Peakvalues(vectors,mid+1,last);


            first=last;
        }
        else 
        	if (vectors[mid] > vectors[mid + 1])
            {
            	last = mid-1;
            }
        	else
       		{
            	first = mid + 1;
        	}
    }
}

int main()
{
	printf("how many lines and collumns should the matrix have note that they are the same so read only a number \n");
    int nrelem,i,j;
    scanf("%d",&nrelem);

    int Matrix[20][20];
    srand(time(NULL));

    for( i=0; i<nrelem; i++)
    {
        for( j=0; j<nrelem; j++)
        {
            Matrix[i][j]=rand()%100;
        }
    }

    for( i=0; i<nrelem; i++)
        {
            for( j=0; j<nrelem; j++)
            {
                printf("%d ",Matrix[i][j]);
            }
            printf("\n");
        }

       printf("\n\nPeak values: ");

       //In the essence a 2d vector(a matrix) is a vector of vector, so if i send the matrix[i] i actually send
       //the adrees of the first element from the line i 
       // so i used the fact that a matrix is a vector of vectors by using peakvalues(matrix(i),0,nrelem);

    for( i=0 ; i<nrelem; i++)
    {

        if(Matrix[i][0] > Matrix[i][1] || Matrix[i][0] < Matrix[i][1])
        {
            printf("%d ",Matrix[i][0]);
        }
        if(Matrix[i][nrelem-1]>Matrix[i][nrelem-2]|| Matrix[i][nrelem-1] < Matrix[i][nrelem-2])
        {
            printf("%d ",Matrix[i][nrelem-1]);
        }

        Peakvalues(Matrix[i], 0, nrelem);
    }

    printf("\n");

    return 0;
}