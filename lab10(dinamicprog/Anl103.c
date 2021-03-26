#include<stdio.h>

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