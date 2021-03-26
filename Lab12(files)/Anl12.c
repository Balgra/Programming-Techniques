/*
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
*/

/*
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

}*/




#include<stdio.h>

int main(int argc, char *argv[])
{
    FILE *file;
    for(int i = 1; i < argc; i++)
   {
       file = fopen(argv[i], "r");
       
       if(file==NULL)
       {
           printf("File %s not found!\n", argv[i]);
       }
       else
       {

        	int chars;
        	while((chars=fgetc(file))!=EOF)
       		 {

        	  	  if(chars == '\n')
        	  	  {
           	     	fprintf(stdout,"\r");
           	     }
           		 fprintf(stdout,"%c",chars);

        	}
       }
    }
    return 0;
}



