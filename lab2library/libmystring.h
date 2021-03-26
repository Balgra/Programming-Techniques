//void hello(void); // un fel de interfata, acestea sunt funcitile si returneaza ce trebuie // just the funciton call
#include<stdio.h>

int mystrlen(const char *dest);

char *mystrncpy(char *dest,const char* src,int n);

int mystrcmp(const char *dest,const char *src);

int mystrncmp(const char *s1, const char *s2,int n);

char *mystrcpy(char *dest,const char *src);

void mymemcpy(void *dest, void *src, int n);

void *mymemset(void *s, char c, int n);

int mymemcmp(const void *s1,const void *s2,int n);

void *mymemchr(const void *str,int c,int n);

char *mystrtoupper(char *dest);

char *mystrtolower(char *dest);

char *mystrcat(char *dest,const char *src);

char *mystrncat(char *dest, const char *src, int n);

char *mystrchr( const char str[], int ch );

char *mystrrchr(const char str[], int ch );

char *mystrrev(char *dest);

char *mystrset(char *dest,char ch);

char *mystrstr(const char *dest,const char *string);

int mystrcspn(char *dest,char *src);

char *mystrpbrk(char *str1, const char *str2);

int indexOF(const char *string, char c);

int lastindexOF(const char *string , char c);

int startWith(const char *string, const char *prefix);