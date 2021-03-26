#include<stdio.h>

int fibvect[100];

int Sirfibbonacci2(int indexsum)
{

	fibvect[0]=0;
	fibvect[1]=1;

	printf("%d ",fibvect[1]);


		for(int i=2;i<=indexsum;i++)
		{
			fibvect[i]=fibvect[i-1]+fibvect[i-2];
			printf("%d ",fibvect[i]);
		}


	return fibvect[indexsum];
}

int main()
{
	int indexsum;

	printf("Give the index of the number in the array which you want to be printed \n");
	scanf("%d",&indexsum);


	Sirfibbonacci2(indexsum); // iteretively with a vector



	return 0;
}