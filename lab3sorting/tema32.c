#include<stdio.h>
#include<stdlib.h>

int counter_afterqsort=0,counter_withoutsorting=0;

int Ft_cmp(const void *r1,const void *r2)
{
	int rw1=*(int*)r1;
	int rw2=*(int*)r2;

	return rw1-rw2;
}

int my_binarysearch(int v[],int left,int right,int nrsearch)
{
	if(left<=right)
	{
		counter_afterqsort++;
		int mid=left+(right-left)/2;
		if(v[mid]==nrsearch)
		{
			return mid;
		}	

		if(v[mid]>nrsearch)
		{
			return my_binarysearch(v,left,mid-1,nrsearch);
		}

		return my_binarysearch(v,mid+1,right,nrsearch);
	}

	return -1;

}

int main()
{
	int v[1000];
	int n=300;
	int flag,switcher=1;
	for(int i=0;i<n;i++)
	{
		v[i]=rand()%1000;
	}
	printf("Give a number to check if it's in the array:");
	int nrsearch,result;
	scanf("%d",&nrsearch);
	printf("nr of searching attemps, '0' without binary search '1' for binary search ");
	scanf("%d",&flag);
	
	if(flag==0)
	{
		for(int i=0;i<n;i++)
		{	
			counter_withoutsorting++;
			if(v[i]==nrsearch)
			{	
				switcher=0;
				printf("is works fine with 0 to n-1,number of searching attemps: %d",counter_withoutsorting);
			}
		}
		if(switcher==1)
		{
			printf("better luck next time \n");
		}
	}

	else
	{
		qsort(v,n,sizeof(int),Ft_cmp);

		result=my_binarysearch(v,0,n-1,nrsearch);

		if(v[result]==nrsearch)
		{
				printf(" \nThe number has beed found, number of searching attemps: %d",counter_afterqsort);
		}
		else
		{
			printf(" \nBetter luck next time");
		}
	}

	return 0;

}