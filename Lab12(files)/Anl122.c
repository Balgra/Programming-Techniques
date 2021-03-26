#include<stdio.h>
#include<stdlib.h>

char characters[256];

int main()
{
 	int Read_Char;

 	while((Read_Char=fgetc(stdin))!=EOF)
 	{
 		characters[Read_Char]++;
 	}

 	for(int i=0;i<256;i++)
 	{
 		if(i==32)
 		{
 			fprintf(stdout,"The character space is %d times tiped by the user: \n",characters[i]);
 		}
 		if(characters[i]>0 && i!=32)
 		{
 			fprintf(stdout,"The character %c is %d times tiped by the user: \n",i,characters[i]);
 		}
 	}

 	return 0;
}