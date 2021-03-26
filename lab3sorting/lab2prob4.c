*#include<stdio.h>
#include<stdlib.h>

int mybinarySearch(int v[], int lft, int rgt, int nrcheck) 
{ 
    if (rgt >= lft) { 
        int mid = (lft + rgt) / 2; 
  
        if (v[mid] == nrcheck) 
            return mid; 
  
        if (v[mid] > nrcheck) 
            return mybinarySearch(v, lft, mid - 1, nrcheck); 
  
        return mybinarySearch(v, mid + 1, rgt, nrcheck); 
    } 
  	
  	printf("The number given can't be found in the array \n");
    exit(-1); 
} 
  
int main()
{
	int nrread=15,nrcheck,fan=1,i,j,k;
	int v[100];
	for(i=2;i<=nrread;i++)
	{
		fan=1;
		for(j=2;j<=i/2;j++)
		{
			if(i%j==0)
			{
				fan=0;
			}
		}
		if(fan==1)
		{
			v[k]=i;
			k++;
		}
	}
	k--;
	printf("Give a number to see if it's in the array ");
	scanf("%d",&nrcheck);
	printf("The position of the number %d is on %d ",nrcheck,mybinarySearch(v,0,k,nrcheck));