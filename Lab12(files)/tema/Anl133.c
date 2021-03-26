#include<stdio.h>
#include<stdlib.h>

//you need GIMP or other applications to see if the program is ok

void Black_Gradient(FILE *blackgra)
{
	fprinf(blackgra,"%d %d \n",1000,1000);

	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<1000;j++)
		{
			fprintf(blackgra,"%d %d %d ",(255*j)/1000,(255*j)/1000,(255*j)/1000);
		}

		fprintf(blackgra,"\n");

	}
}


void Black_Gradient(FILE *violetgra)
{
	fprinf(violetgra,"%d %d \n",1000,1000);

	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<1000;j++)
		{
			fprintf(violetgra,"%d %d %d ",(255*j)/1000,0,(255*j)/1000);
		}

		fprintf(violetgra,"\n");

	}
}


int main()
{
	FILE *blackgra;
	FILE *violetgra;

	blackgra=fopen("blackgradient.ppm","w");

	Black_Gradient(blackgra);

	fclose(blackgra);

	violetgra=fopen("violetgradient.ppm","w");

	Violet_Gradient(violetgra);

	fclose(violetgra);

	return 0;


}