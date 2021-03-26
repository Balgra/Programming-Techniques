//Using dinamic programming find the longest common substring
//Ex: is s1: "ABABC" and s2:"BABCA" the longest common substring
//is BABC of length 4; 
/*
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int lookup[100][100];

char LongComSubs(char String1[],char String2[],int m, int n)
{
	int maxim=0;

	int endingIndex=m;

	for(int i=1; i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(String1[i-1]==String2[j-1])
			{
				lookup[i][j]=lookup[i-1][j-1]+1;

				if(lookup[i][j]>maxim)
				{
					maxim=lookup[i][j];
					endingIndex=i;
				}
			}
		}
	}
	printf("maxim: %d ",maxim);

	for(int i=endingIndex-maxim;i<=maxim;i++)
	{
		printf("%c",String1[i]);
	}
	printf("\n");

	return 0;

}

int main()
{
	int m=5,n=5;

	char String1[100]="ABABC";
	char String2[100]="XBABCA";

	printf("The longest common substring is: ");

	LongComSubs(String1,String2,m,n);


}*/


//rod problem;

/*
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
}*/