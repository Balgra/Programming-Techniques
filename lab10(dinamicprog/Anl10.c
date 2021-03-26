#include<stdio.h>

/*problema 1

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


*/


//problema 2
/*int fibvect[100];

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
}*/

//problema 3

/*
int vcoins[50]; // vector where i have coins
int vectsols[50];//the vector for solutions
int counter=0;//counter for the vector of sols to know the on which elem i;m

int coins(int suma,int indexcoins)
{
	//main action where i put my  solutions 
	//index coins ii sa vad pe ce coin sunt
	if(suma>=vcoins[indexcoins] && indexcoins!=-1)
	{
		vectsols[counter]=vcoins[indexcoins];
		counter++;

		 return coins(suma-vcoins[indexcoins],indexcoins);

	}

	// if the sum is different than 0 and i still have coins left and check.
	if(suma!=0 && indexcoins!=0)
	{	
		return coins(suma,indexcoins-1);
	}
	//just the printing of the solution for one index
	if(suma==0)
	{
		for(int i=0;i<counter;i++)
		{
			printf("%d ",vectsols[i]);
		}
		printf("\n");
		counter=0;
		return 0;
	}
	
	

return 0;


}

int main()
{
	int nrcoins,suma;
	printf("Give the number of how many coins and the sum, after that the actual coins exe 1 5 10 25 \n");
	scanf("%d %d",&nrcoins,&suma);

	for(int i=0;i<nrcoins;i++)
	{
		scanf("%d", &vcoins[i]);
	}


	// here i start from coin max to coin min. (de la mic la mare, o sa fac o functie care sa imi sorteze asta dupa :))) )
	for(int i=nrcoins;i>=1;i--)
	{

		coins(suma,i-1);

	}

	return 0;

}
*/


///problema 3 refacuta

int Numbercoins;
int combinations[100];
int comblength=0;

/*
void printamout(int combinations[])
{
	for (int i=0;i<=comblength;i++)
	{
		printf("%d  ",combinations[i]);
	}
	printf("\n");

}*/

int coinalgorithm(int amount, int coins[])
{
	combinations[0]=1;
	int indexcoin,indexcomb;
	comblength=amount;

	for(  indexcoin=0; indexcoin<Numbercoins; indexcoin++)
	{

		for(indexcomb=1;indexcomb<amount+1;indexcomb++)
		{

			if(indexcomb>= indexcoin)
			{

				combinations[indexcomb]=combinations[indexcomb]+combinations[indexcomb-coins[ indexcoin]];
				///printamout(combinations);
			}
		}
		///printf("\n");
	}

	printf("%d \n",combinations[amount]);
	
	return 0;
}

int main()
{

	int change;
	printf("Which shall be the change which will be disembeld \n");
	scanf("%d",&change);

	printf("Also give the number of coins we have to work with, also, the coins \n");
	scanf("%d",&Numbercoins);

	int coins[100];
	for(int i=0;i<Numbercoins;i++)
	{
		scanf("%d",&coins[i]);
	}

	coinalgorithm(change,coins);

}