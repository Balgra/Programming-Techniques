#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>


struct node
{
	char info[20];
	struct node *prev;
	struct node *next;
};


void sortlist(struct node *head)
{
	struct node *i, *j;
	char aux[20];

	for(i=head;i->next!=NULL;i=i->next)
	{
		for(j=i->next;j!=NULL;j=j->next)
		{
			if(strcmp(i->info , j->info)>0)
			{
				strcpy(aux,i->info);
				strcpy(i->info,j->info);
				strcpy(j->info,aux);
			}
		}
	}

	printf("the list after it is sorted: \n");
	i=head;
	while(i!=NULL)
	{
		printf("%s",i->info);
		i=i->next;
	}

}

int pick=1;

struct node *Childgame(struct node *start,int nrelem,int chnr)
{
	if(pick==1)
	{
		int index=0;
		int whout=1;
		while(index!=nrelem-1)
		{
			if(whout==chnr)
			{
				start->prev->next=start->next;
				start->next->prev=start->prev;
				printf("%s",start->info);
				free(start);
				if(chnr!=1)
				{
					start=start->next;
				}
				index++;
				whout=1;
			}
			start=start->next;
			whout++;
			if(chnr==1)
			{
				whout=1;
			}
		}

		return start;
    }

    if(pick==2)
	{
		int index=0;
		int whout=1;
		while(index!=nrelem-1)
		{
			if(whout==chnr)
			{
				start->prev->next=start->next;
				start->next->prev=start->prev;
				printf("%s",start->info);
				free(start);
				if(chnr!=1)
				{
					start=start->prev;
				}
				index++;
				whout=1;
			}
			start=start->prev;
			whout++;
			if(chnr==1)
			{
				whout=1;
			}
		}

		return start;
    }

    return 0;

}

int main()
{
	FILE *fin;

	char s[20];
	struct node *head=NULL, *tail=NULL, *current=NULL;

	head=(struct node*)malloc(sizeof(struct node));

	fin=fopen("tema6.txt","r");

	if(fin==NULL)
	{
		printf("eroare la citirea din fisier");
	}

		fgets(s,20,fin);
		strcpy(head->info,s);
		head->next=NULL;
		head->prev=NULL;
		current=head;
		tail=head;

		int nrelem=1,chnr;

	while(fgets(s,20,fin)!=NULL)
	{
		current=(struct node*)malloc(sizeof(struct node));
		strcpy(current->info,s);
		current->next=NULL;
		current->prev=NULL;

		tail->next=current;
		current->prev=tail;
		tail=current;
		nrelem++;
	}

	sortlist(head);

	tail->next=head;
	head->prev=tail;

	printf("Choose a number to counter whose is out of the game and 1 for clockwise and 2 for reverclockwise :\n");
	scanf("%d %d",&chnr,&pick);

	if(pick==1)
	{
		head=Childgame(head,nrelem,chnr);
	}
	else
	{
		head=Childgame(tail,nrelem,chnr);
	}

	printf("The winner is: %s",head->info);


	return 0;

}