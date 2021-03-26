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
}