#include<stdio.h>


int main()
{
	int character;

	while((character=fgetc(stdin))!=EOF)
	{
		if(character=='\n')
		{
			fprintf(stdout,"\r");
		}

		fprintf(stdout,"%c",character);
	}

	return 0;

}