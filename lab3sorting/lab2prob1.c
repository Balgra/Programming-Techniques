#include<stdio.h>
#include<stdlib.h>
void sorting(int v[],int n)
{
	int i,j;
	int aux;
	for(i=1;i<n;i++)
	{
		aux=v[i];
		for(j=i-1;j>=0 && aux<v[j];j--)
		{
			v[j+1]=v[j];
		}
			v[j+1]=aux;
	}


}
int main()
{
	int v[100], n=10;
	for(int i=0;i<=n;i++)
	{
		v[i]=rand()%1000;
		printf("%d ",v[i]);
	}
	printf("\n");
	sorting(v,n);
	for(int i=0;i<n;i++)
	{
		printf(" %d ",v[i]);
	}	
}