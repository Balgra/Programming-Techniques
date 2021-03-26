#include<stdio.h>//strings part1 
#include<string.h>
int Stleng(char s[])
{
	int i=0;
	while(s[i]!='\0')
	{
		i++;
	}
	return i;
}
// size_t aproape la fel ca si unsigned long 
// print string to hex.
void printStringTohex(char s[])
{
	int i=0;
	// daca voiam cu for l=strlen(s) si for i,l,i++.
	while(s[i]!='\0')
	{
		printf("%02x ",s[i]);// %02x, daca dau \n imi afiseaza 0a
		i++;
	}
}
/* 
codul lui 0 in asci e 48 (baza 10) in baza 16 e 30
codul lui \n in asci e 10 , in baza 16 e 0a;
*/
int main()
{
	// "abcs12"-constant string.
	//char s[100]="ABC\nDE";// 41 42 43 0a 44 45
	char s[100]="\x41\x42";// hex escape sequence out of range
	int i;
	for(i=0;i<strlen(s);i++)
	{
		printf("%u ",s[i]);
	}
	printf("\n");
	//printf("%s \n",s);
	//char s[] mai mult pt functii.
	//declare and initialize a char,write a function that return it;s lenght.
	//printf("the lenght is %lu \n",strlen(s)); 
	//Stleng(&s[1]));//incepe numaratoarea de la 1 , maybe it helps for some problems
	//printStringTohex(s);
	return 0;
}