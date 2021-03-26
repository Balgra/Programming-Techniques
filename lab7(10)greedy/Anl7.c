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

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


void SwapChar(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  */
  /*
  01=10 174 12=21 152 23=32 393 43=34 388 
  02=20 315 13=31 544 24=42 449
  03=30 634 14=41 595
  04=40 544
  */
/*
int v[100];
int min=999999;
void PermuteChar(char *a, int l, int r) 
{ 
   int i,j=0;
   if (l == r) 
   {
    v[j]=0;
     printf("the route is %s ", a); 
     for(i=0;i<5;i++)
     {
        if((a[i]=='0' && a[i+1]=='1')|| (a[i]=='1' && a[i+1]=='0'))
         {
          v[j]=v[j]+174;
         }
         if((a[i]=='0' && a[i+1]=='2')|| (a[i]=='2' && a[i+1]=='0'))
         {
          v[j]=v[j]+315;
         }
         if((a[i]=='0' && a[i+1]=='3')|| (a[i]=='3' && a[i+1]=='0'))
         {
          v[j]=v[j]+634;
         }
         if((a[i]=='0' && a[i+1]=='4')|| (a[i]=='4' && a[i+1]=='0'))
         {
          v[j]=v[j]+544;
         }
         if((a[i]=='1' && a[i+1]=='2')|| (a[i]=='2' && a[i+1]=='1'))
         {
          v[j]=v[j]+152;
         }
         if((a[i]=='1' && a[i+1]=='3')|| (a[i]=='3' && a[i+1]=='1'))
         {
          v[j]=v[j]+544;
         }
          if((a[i]=='1' && a[i+1]=='4')|| (a[i]=='4' && a[i+1]=='1'))
         {
          v[j]=v[j]+595;
         }
          if((a[i]=='2' && a[i+1]=='3')|| (a[i]=='3' && a[i+1]=='2'))
         {
          v[j]=v[j]+393;
         }
          if((a[i]=='2' && a[i+1]=='4')|| (a[i]=='4' && a[i+1]=='2'))
         {
          v[j]=v[j]+499;
         }
          if((a[i]=='4' && a[i+1]=='3')|| (a[i]=='3' && a[i+1]=='4'))
         {
          v[j]=v[j]+388;
         }
     }

     printf("and the length %d \n",v[j]);
     if(a[0]=='1')
     {
        if(v[j]<min)
        {
          min=v[j];
        }
     }
     j++;

   }
   else
   { 
       for (i = l; i <= r; i++) 
       { 
          SwapChar((a+l), (a+i)); 
          PermuteChar(a, l+1, r); 
          SwapChar((a+l), (a+i)); 
       } 
   } 
} 
  

int main() 
{ 
    char str[] = "01234"; 

    int n = strlen(str); 
    printf("0-Timisoara, 1-Oradea, 2-Cluj-Napoca, 3-Iasi, 4-Bucuresti \n");
    PermuteChar(str, 0, n-1); 

    printf("And the minimum route starting with Oradea (1) is %d \n",min);
    return 0; 
}*/


/*
#include<stdio.h>

int flag=0;

int dividelower(int array[], int start, int end)
{
	for(int i=start;i<=end;i++)
	{
		if(array[i-1] < array[i] && array[i] > array[i+1])
		{
			flag=1;
			printf("%d ",array[i]);
		}

		if(array[i-1] > array[i] && array[i] < array[i+1])
		{
			flag=1;
			printf("%d ",array[i]);
		}
	}
	return 0;
}

int divideupper(int array[], int start, int end)
{
	for(int i=start;i<end-1;i++)
	{
		if(array[i-1] < array[i] && array[i] > array[i+1])
		{
			flag=1;
			printf("%d ",array[i]);
		}

		if(array[i-1] > array[i] && array[i] < array[i+1])
		{
			flag=1;
			printf("%d ",array[i]);
		}
	}
	return 0;
}

int main()
{
	int n, array[100],i,mid;

	printf("How many elements do you want in the array? \n");
	scanf("%d",&n);

	for(i=0 ;i<n; i++)
	{
		scanf("%d", &array[i]);
	}
		for(i=0 ;i<n; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");
	//printf("Preak elements: ");
	mid=n/2;

	dividelower(array, 1,mid-1);

	if(array[mid-1] < array[mid] && array[mid] > array[mid+1])
		{
			flag=1;
			printf("%d ",array[mid]);
		}

	if(array[mid-1] > array[mid] && array[mid] < array[mid+1])
		{
			flag=1;
			printf("%d ",array[mid]);
		}

	divideupper(array, mid+1, n);

	if(flag==1)
	{
		printf(" - These are the peak elements ");
	}
	else
	{
		printf("There are no peaks!");
	}

	printf("\n");

	return 0;

}*/