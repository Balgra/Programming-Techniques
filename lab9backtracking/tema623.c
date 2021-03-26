//read form a file a double linked list filled with random characters that from a sentence
//Make a function that sort ascendingly, anyhow, the list and print the result on the screan.
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

int main()
{
	FILE *fin;

	char s[20];
	struct node *head=NULL, *tail=NULL, *current=NULL;

	head=(struct node*)malloc(sizeof(struct node));

	fin=fopen("tema623.txt","r");

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

	while(fgets(s,20,fin)!=NULL)
	{
		current=(struct node*)malloc(sizeof(struct node));
		strcpy(current->info,s);
		current->next=NULL;
		current->prev=NULL;

		tail->next=current;
		current->prev=tail;
		tail=current;
	}

	sortlist(head);

	return 0;

}