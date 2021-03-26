#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct studenti
{
	char txt[255];
	int grades;
}studenti_t;

void gradesorting(studenti_t v[],int n)
{
	int i,j;
	studenti_t aux;
	for(i=1;i<n;i++)
	{
		aux=v[i];
		for(j=i-1;j>=0 && aux.grades<v[j].grades;j--)
		{
			v[j+1]=v[j];
		}
			v[j+1]=aux;
	}


}

void namesorting(studenti_t v[],int n)
{
	int i,j;
	studenti_t aux;
	for(i=1;i<n;i++)
	{
		aux=v[i];
		for(j=i-1;j>=0 && strcmp(aux.txt,v[j].txt)<1;j--)
		{
			v[j+1]=v[j];
		}
			v[j+1]=aux;
	}


}

int main()
{
	int choice;
	int numstud,k=0,i;
	studenti_t s[100];
	do
	{
		printf("This is the your menu\n");
		printf("0 for exit \n");
		printf("1 for how many student \n");
		printf("2 enter all the students and their grades\n");
		printf("3 Display class in alphabetic order \n");
		printf("4 Display class creating a top based on grades \n");
		printf("5 Display the first 3 students according to their grades \n");

		scanf("%d",&choice);
		switch (choice)
		{
			case 0:
					printf("that was it");
					exit(0);
					break;
			case 1: 
					
					if(scanf("%d",&numstud)!=1)
					{
					  	printf("bad input");
					}
					break;

			case 2:	
					while(k<numstud)
					{
						if(scanf("%s",s[k].txt)!=1)
						{
							printf("bad input");
						}
						if(scanf("%d",&s[k].grades)!=1)
						{
							printf("bad input");
						}
						k++;
					}
					break;

			case 3:	namesorting(s,k);

					for(i=0;i<k;i++)
					{
						printf("%s \n",s[i].txt);
					}
					break;

			case 4: gradesorting(s,k);
					for(i=0;i<k;i++)
					{
						printf("%s %d \n",s[i].txt,s[i].grades);
					}
					break;

			case 5: printf("%s %s %s \n",s[k-1].txt,s[k-2].txt,s[k-3].txt);
					break;

			default: printf("that was it ");
					break;
		}



	}while(choice!=0);
}