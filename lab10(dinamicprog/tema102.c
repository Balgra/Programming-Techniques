#include<stdio.h>

int RodCut(int PriceRods[],int rod)
{
	int costrod=0;
	int maxim=-1;

	if(rod==0)
	{
		return 0;
	}

	for(int i=1;i<=rod;i++)
	{
		costrod=PriceRods[i-1]+RodCut(PriceRods,rod-i);

		if(costrod>maxim)
		{
			maxim=costrod;
		}
	}

	return maxim;

}

int main()
{
	//int LengthRod[]={1,2,3,4,5,6,7,8};
	int PriceRods[]={1,5,8,9,10,17,18,20};

	int rod=6;

	printf("The maximum profit can be: %d",RodCut(PriceRods,rod));

	return 0;
}