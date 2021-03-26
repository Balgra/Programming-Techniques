// exe 1 tema 3.

//insertion sort;
/*#include<stdio.h>
#include<stdlib.h>

int Insertioncounter=0,Mergecounter=0;


void insertion_sort(int w[], int n)  
{  
    int counter1, aux, counter2;  
    for (counter1 = 1; counter1 < n; counter1++) 
    {  
        aux = w[counter1];  
        counter2 = counter1 - 1;  
  
        while (counter2 >= 0 && w[counter2] > aux) 
        {  
            w[counter2 + 1] = w[counter2];  
            counter2 = counter2 - 1;  
            Insertioncounter++;
        }  
        w[counter2 + 1] = aux;  
    }  
}  

void mymerge(int w[],int left,int right,int mid)
{
	int counter1, counter2, counter3;
	int elements1 = mid - left + 1;
	int elements2 = right - mid;
	int Left[elements1],Right[elements2];

	for (counter1 = 0; counter1 < elements1; counter1++) 
        Left[counter1] = w[left + counter1]; 
    for (counter2 = 0; counter2 < elements2; counter2++) 
        Right[counter2] = w[mid + 1 + counter2]; 
  
    counter1 = 0; 
    counter2 = 0;
    counter3 = left;
    while (counter1 < elements1 && counter2 < elements2) 
    { 
        if (Left[counter1] <= Right[counter2]) 
        { 
            w[counter3] = Left[counter1]; 
            counter1++; 
            Mergecounter++;
        } 
        else
        { 
            w[counter3] = Right[counter2]; 
            counter2++; 
            Mergecounter++;
        } 
        counter3++; 
    } 
  

    while (counter1 < elements1) 
    { 
        w[counter3] = Left[counter1]; 
        counter1++; 
        counter3++; 
        Mergecounter++;
    } 


    while (counter2 < elements2) 
    { 
        w[counter3] = Right[counter2]; 
        counter2++; 
        counter3++; 
        Mergecounter++;
    } 
} 


void merge_sort(int w[],int left,int right)
{
	if(left<right)
	{
		int mid=left+(right-left)/2;
		merge_sort(w,left,mid);
		merge_sort(w,mid+1,right);

		mymerge(w,left,right,mid);
	}
}

int main()
{
	int v[1000],w[1000];
	int n=200,i;

	for(i=0;i<n;i++)
	{
		v[i]=rand();
		w[i]=v[i];
	}

	insertion_sort(v,n);

	merge_sort(w,0,n-1);

		printf("insertion is better %d \n",Insertioncounter);
		printf("Merge is better %d \n",Mergecounter);

}*/

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