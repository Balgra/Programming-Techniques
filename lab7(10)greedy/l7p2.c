#include<stdio.h>
#include<stdlib.h>


int Towns[10][10];
int route[11], length,visited[11];
int n;

void SearchTwon(int previous, int *next, int *distance)
{
	int i;
	*distance=99999;

	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			if(Towns[previous][i]< *distance && Towns[previous][i]!=0)
			{
				*distance=Towns[previous][i];
				*next=i;
			}
		}
	}
}
void erase()
{
	int i;

	for(i=0;i<12;i++)
	{
		route[i]=0;
		visited[i]=0;
	}

}
int main()
{
 
  int i, j, minv,next;
  FILE *fin;
  fin = fopen("Anl7.txt", "r");

  if (fin==NULL) {
    printf("Error: cannot open input file.\n");
    exit(1);
  }

  fscanf(fin, "%d", &n);

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      fscanf(fin, "%d ", &Towns[i][j]);
    }
  }
  printf("0-Timisoara, 1-Oradea, 2-Cluj-Napoca, 3-Iasi, 4-Bucuresti \n");
   for (i = 0; i < n; i++)
   { 
    	for (j = 0; j < n; j++)
   	 {	
    		printf("%d ",Towns[i][j]);
   	 }
   	 printf("\n");
   }

   	for(int j=0;j<n-1;j++)
   	{
   		erase();
   		route[0]=j;
   		length=0;
   		visited[j]=1;
   		next=0;
   		minv=0;

   		for(i=0;i<n-1;i++)
   		{
   			SearchTwon(route[i],&next,&minv);

   			printf("We choose the road (%d, %d) of the distance %d \n",route[i], next, minv);
   			route[i+1]=next;
   			visited[next]=1;
   			length=length+minv;
   		}
   		 printf("\nThe path has total length %d and is:\n",length);
   		  for (i = 0; i < n; i++)
   		  {
    			printf("%d ", route[i]);
   		  }
    		printf("\n");
   }

  printf("\n");

}