#include "libmystring.h"

int main()
{
	char s1[50]="asas";
	char s2[50]="ANISasa";
	char s3[50]="NAScar";
	char s4[50]="NAScarp";
	char s5[50]="Sax";
	char s6[50]="xzy";
	char s7[50]="ana are x merez";
	char s8[50]="apa mara";
	char *p;
	printf("%d \n",mystrlen(s1));

	mymemcpy(s3,s4,3);

	printf("%s \n",s3);

	mymemset(s8,'%',5);

	printf("%s \n",s8);

	p=mymemchr(s7,'x',10);
	printf("%s \n",p);

	printf("%d \n",mymemcmp(s7,s8,3));

	printf("%d \n",mystrcmp(s1,s2));

	printf("%d \n",mystrncmp(s3,s5,2));

	printf("%s \n",mystrncpy(s1,s2,2));

	printf("%s \n",mystrcpy(s1,s2));// this function should pe called iff the capacity of s1 and s2 are know to avoid buffer overflow.

	printf("%s \n",mystrtoupper(s1));

	printf("%s \n",mystrtolower(s2));

	printf("%s \n",mystrcat(s1,s2));

	printf("%s \n",mystrncat(s1,s2,3));

	printf("%s \n",mystrchr(s2,'I'));

	printf("%s \n",mystrrchr(s7,'x'));

	printf("%s \n",mystrrev(s2));

	printf("%s \n",mystrset(s3,'#'));

	printf("%s \n",mystrstr(s4,s5)); 

	printf("%d \n",mystrcspn(s6,s3));

	p=mystrpbrk(s6,s7);
	printf("%c \n",*p);

	return 0;

}