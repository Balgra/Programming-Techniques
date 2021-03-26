#include <stdio.h> 
#include<string.h>
#include<ctype.h>
// aici implementez 
/*
gcc -Wall -O3 -pedantic -c -o libhello.o libhello.c
gcc -Wall -O3 -pedantic -c main.c -o main.o
ar rcs libhello.a libhello.o
gcc -Wall -O3 -pedantic -o main.x main.o -L. -lhello // toate 4
./main.x astea mereu trb sa le fac pentru ca recompilez tot.
 cat mystring.c > myfisier.c imi face o copie perfecta.
*/
/*void hello(void) 
{
		printf("Hellox, library world. 1\n");
		printf("ASDFASDF");
}*/
int mystrlen(const char *dest)
{
	int i=0;

	while(dest[i])
	{
		i++;
	}
	return i;

}
char *mystrncpy(char *dest, const char *src , int n)
{
	int i=0;

	for(i=0;i<n && src[i]!='\0';i++)
	{
		dest[i]=src[i];
	}

	dest[i]='\0';

	return dest;

}
int mystrcmp(const char *s1, const char *s2)
{

	int i=0;

	while(s1[i] && s2[i])
	{
		if(s1[i] < s2[i])
		{
			return -1;
		}
		if(s1[i] > s2[i])
		{
			return 1;
		}

		i++;
	}

	return 0;
	
}

int mystrncmp(const char *s1, const char *s2,int n)
{

	int i=0;
	int counter=0;

	while(s1[i] && s2[i] && counter<n)
	{
		if(s1[i] < s2[i])
		{
			return -1;
		}
		if(s1[i] > s2[i])
		{
			return 1;
		}
		i++;
		counter++;
	}

	return 0;
	
}

char *mystrcpy(char *dest, const char *src)
{
	int i=0;

	while(src[i])
	{
		dest[i]=src[i];i++;
	}
	return dest;
}

char *mystrtoupper(char *dest)
{
	int i=0;

	while(dest[i])
	{
		if(dest[i]>='a' && dest[i]<='z')
		{
			dest[i]=dest[i]-32;
		}

		i++;

	}

	return dest;
}

char *mystrtolower(char *dest)
{
	int i=0;

	while(dest[i])
	{
		if(dest[i]>='A' && dest[i]<='Z')
		{
			dest[i]=dest[i]+32;
		}

		i++;
		
	}

	return dest;
}

char *mystrcat(char *dest, const char *src)
{
	strcpy(dest+mystrlen(dest),src);

	return dest;

}


char *mystrncat(char *dest, const char *src, int n)
{
	int i=mystrlen(dest);//i is an auxiliary so I can end my array at the wanted position i+n ;

	strcpy(dest+mystrlen(dest),src);

	dest[i+n] = '\0';
	
	return dest;

}

char *mystrchr( const char str[], int ch ) 
{
	int i=0;
	char *p=NULL;

	while(str[i])
	{
		if(str[i]==(char)ch)
		{
			p = ((char *) &str[i]);
		}
		
		i++;
	}

	return p;
}

char *mystrrchr(const char str[], int ch)
{
	int i=mystrlen(str)-1;
	char *p=NULL;

	while(i!=-1)
	{
		if(str[i]==(char)ch)
		{
			p = ((char*) &str[i]);
		}
		i--;
	}

	return p;

}

char *mystrrev(char *dest)
{
	int i=0;
	char aux;
	int j=mystrlen(dest)-1;

	while(i!=(mystrlen(dest)/2))
	{
		aux=dest[i];
		dest[i]=dest[j];
		dest[j]=aux;
		i++;
		j--;
	}

	return dest;

}
char *mystrset(char *dest,char ch)
{
	int i;

	for(i=0;i<mystrlen(dest);i++)
	{
		dest[i]=ch;
	}

	return dest;

}

char *mystrstr(char *dest,const char *string)
{
	int i=0,j=0;

	while(dest[i]!='\0')
	{
		char *find= &dest[i];
		j=0;
			while((dest[i]==string[j]))
			{
				i++;
				j++;
			}
			if(j==mystrlen(string))
			{
				return find;
			}
		i++;
	}

	return NULL;
}


int mystrcspn(char *dest,char *src)
{
	int counter=0;
	int i=0;

	while(dest[i]!='\0')
	{
		if(!mystrchr(src,dest[i]))
		{
			counter++;
		}
		i++;

	}

	return counter;

}

char *mystrpbrk(char *str1, const char *str2)
{
	int i=0,j=0;

	while(str1[i])
	{
		j=0;
		while(str1[i]!=str2[j] && str2[j]!='\0')
		{
			j++;
		}
		if(str1[i]==str2[j])
		{
			return &str1[i];
		}

		i++;

	}

	return NULL;

}


void mymemcpy(void *dest, void *src, int n)
{
	char *chdest= (char*)dest;
	char *chsrc= (char*)src;

	int i=0;

	for(i=0;i<n;i++)
	{
		chdest[i]=chsrc[i];
	}
	i++;
	chdest[i]='\0';
}

void *mymemset(void *s, char c, int n)
{
	char *string=(char *)s;
	int i=0;

	while(n!=0)
	{
		string[i]=c;
		i++;
		n--;
	}

	return string;
}

int mymemcmp(const void *s1,const void *s2,int n)
{
	const char *string1=(char*)s1;
	const char *string2=(char*)s2;
	int i=0;

	while(n!=0)
	{
		if(string1[i]>string2[i])
		{
			return 1;
		}
		else
			if(string1[i]<string2[i])
			{
				return -1;
			}
			else
			{
				return 0;
			}
		n--;
	}

	return 0;
}

void *mymemchr(const void *str,int c,int n)
{
	int i=0;
	char *p=(char*)str;

	while(n!=0)
	{
		if(p[i] == (char) c)
		{
			return &p[i];
		}
		else
			i++;
		n--;
	}

	return NULL;

}


int indexOF(const char *string, char c)
{
	int i;

	for(i=0; i<mystrlen(string); i++) // i!='\n'
	{
		if(string[i]==c)
		{
			return i;
		}
	}

	return -1;
}

int lastindexOF(const char *string , char c)
{
	int i,index=0;

	for(i=0;i<mystrlen(string);i++)
	{
		if(string[i]==c)
		{
			index=i;
		}
	}

	if(index==0)
	{
		return -1;
	}
	else
	{
		return index;
	}
}

int startWith(const char *string, const char *prefix)
{
	int i;

	for(i=0; i<mystrlen(prefix); i++)
	{
		if(prefix[i]!=string[i])
		{
			return -1;
		}
	}

	return 1;
}