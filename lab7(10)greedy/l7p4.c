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

}