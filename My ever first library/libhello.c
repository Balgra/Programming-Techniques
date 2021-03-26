#include <stdio.h> // aici implementez 
/*
gcc -Wall -O3 -pedantic -c -o libhello.o libhello.c
gcc -Wall -O3 -pedantic -c main.c -o main.o
ar rcs libhello.a libhello.o
gcc -Wall -O3 -pedantic -o main.x main.o -L. -lhello
./main.x astea mereu trb sa le fac pentru ca recompilez tot.
*/
void hello(void) 
{
		printf("Hellox, library world. 1\n");
		printf("ASDFASDF");
}