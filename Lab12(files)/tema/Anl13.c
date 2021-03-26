/*#include<stdio.h>

void UptoLow(FILE *fin)
{
	int c;

	while((c=fgetc(fin))!=EOF)
	{
		if(c>='a' && c<='z')
		{

			fprintf(fin,"%c",c-32);
		}

	}

}

int main(int argc, char *argv[])
{
	//printf("It works %s %d \n",argv[0],argc);

	FILE *fin;

	if(argc>1)
	{
		fin=fopen(argv[1],"r+");
	}
	else
	{
		printf("probleme la command line \n");

		return 0;
	}

	if(fin==NULL)
	{
		printf("probleme la fisier pls no \n");

		return 0;
	}


	UptoLow(fin);

	fclose(fin);

}*/

/*
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define Pi 3.14159265358979323846

int reverstan(double x)
{
	return 1/tan(x);
}

int main(int argc, char *argv[])
{
	//printf("It works %s %d \n",argv[0],argc);

	FILE *fout;

	if(argc>1)
	{
		fout=fopen(argv[1],"r+");
	}
	else
	{
		printf("probleme la command line \n");

		return 0;
	}

	if(fout==NULL)
	{
		printf("probleme la fisier pls no \n");

		return 0;
	}

	fprintf(fout, "   Degrees      Radians        sin(x)          cos(x)          tan(x)          reverstan(x)\n");
    fprintf(fout, " ============================================================================================ \n");

    for(float i=0;i<=90;i++)
    {
    	float radian= i*(Pi/180);
    	fprintf(fout," %.1f             %.3f           %.3f            %.3f           %.3f        %.3d \n",i,radian,sin(i),cos(i),tan(i),reverstan(i));
    }

    fclose(fout);

	return 0;
}*/

/*
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


}*/
