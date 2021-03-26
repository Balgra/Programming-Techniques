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