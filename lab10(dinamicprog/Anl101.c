#include<stdio.h>

int Sirfibbonacci(int indexsum)
{
	if(indexsum==0)
	{
		return 0;
	}
	else
		if(indexsum==1)
		{
			return 1;
		}
		else
		{
			return Sirfibbonacci(indexsum-1)+Sirfibbonacci(indexsum-2);
		}
}


int Sirfibbonacci2(int indexsum)
{
	int fibvect[100];

	fibvect[0]=0;
	fibvect[1]=1;


		for(int i=2;i<=indexsum;i++)
		{
			fibvect[i]=fibvect[i-1]+fibvect[i-2];
		}


	return fibvect[indexsum];
}

int main()
{
	int indexsum;

	printf("Give the index of the number in the array which you want to be printed \n");
	scanf("%d",&indexsum);

	//printf("%d",Sirfibbonacci(indexsum)); // recursively


	printf("%d",Sirfibbonacci2(indexsum)); // iteretively with a vector



	return 0;
}
