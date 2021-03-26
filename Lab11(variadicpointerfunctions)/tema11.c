
#include <stdio.h>
#include <stdarg.h>
#include<math.h>
#include<string.h>
 
void myprintf(const char* format, ...)
{
    va_list arguments;

    va_start(arguments, format);
 
    while (*format != '\0')
     {
     	if(*format== 's')
     	{
     		char string[255];

     		strcpy(string,va_arg(arguments,char *));

     		int i=0;

     		while(i!=strlen(string))
     		{
     			putchar(string[i]);
     			i++;
     		}
     		putchar('\n');

     	}
        if (*format == 'd')
        {
            int i = va_arg(arguments, int);
            int num=0;
            while(i>0)
            {
            	num=num*10+i%10;
            	i=i/10;
            }
            while(num>0)
            {
            	 putchar(num%10+'0');
            	 num=num/10;
            }

            putchar('\n');
        }
         else
         
         	 if (*format == 'c') 
        	 {
          		 int c = va_arg(arguments, int);
           		 //printf("%c\n", c);
           		 putchar((char)c);
           		 putchar('\n');
       		 } 
       		 else
        	{
         			if(*format == 'f') 
        			{
           				 double d = va_arg(arguments, double);
           				 int counter=0;
           				 while((int)d%10!=0)
           				 {
           				 	d=d*10;
           				 	counter++;
           				 }
           				 d=d/10;
           				 counter--;

           				 int nrcifre=0;
           				 int num=(int)d;

           				 while(num>0)
           				 {
           				 	num=num/10;
           				 	nrcifre++;
           				 }

           				 counter=nrcifre-counter;

           				 num=(int)d;

           				 int deafisat=0;

           				 while(num>0)
           				 {
           				 	deafisat=deafisat*10+num%10;
           				 	num=num/10;
           				 }
           				int  point=0;
           				 while(deafisat>0)
           				 {
           				 	if(point==counter)
           				 	{
           				 		putchar('.');
           				 	}
           				 	putchar(deafisat%10+'0');
           				 	point++;
           				 	deafisat=deafisat/10;

           				 }

           				 putchar('\n');
        			}
        	}

        ++format;
    }
 
    va_end(arguments);
}
 
int main()
{
   myprintf("dcfffcs", 123, 'a', 1.999, 42.5,123.2,'a',"ana"); 
}
