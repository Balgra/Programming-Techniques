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


void sortlist(struct node *head) // asa se poate sorta o lista dublu inlantuita dupa o facem circulara.
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

//aici codul mare lung, dar, dar e faza ca am facut cu clockwise or reverclockwise 
// si atunci mna de aceea pare lung, dar e exact cam acelasi cod (doar parcurgerea difera)
struct node *Childgame(struct node *start,int nrelem,int chnr)
{
	if(pick==1)
	{
		int index=0;
		int whout=1;
		//whout insemana cine iese din joc, si il cresc mereu pana cand e egal cu numarul ales
		//nr ales e chnr, adica cine iese. cand e egal cu acest numar, tai acel nod , dau freee la acel nod.
		// am putut sa fac totul cu un nod pentru ca am facut cu nod>prev>next VEZI PE HARTIE ASTA TE ROG.
		while(index!=nrelem-1)
		{
			if(whout==chnr)
			{
				start->prev->next=start->next;
				start->next->prev=start->prev;
				printf("Is out %s",start->info);
				free(start);
				if(chnr!=1) // parcurgere
				{
					start=start->next;
				}
				index++;
				whout=1;
			}
			start=start->next; // parcurgere
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
				printf("Is out %s",start->info);
				free(start);
				if(chnr!=1)
				{
					start=start->prev; //parcurgere
				}
				index++;
				whout=1;
			}
			start=start->prev; // parcurgere
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
	//citire din fisier a mai multe elemente.
	FILE *fin;

	char s[20];
	struct node *head=NULL, *tail=NULL, *current=NULL;

	head=(struct node*)malloc(sizeof(struct node));

	fin=fopen("tema6.txt","r");

	if(fin==NULL)
	{
		printf("eroare la citirea din fisier");
	}

		// pun  primul element din fisier in primul nod aka head.
		fgets(s,20,fin);
		strcpy(head->info,s);
		head->next=NULL;
		head->prev=NULL;
		current=head;
		tail=head;

		int nrelem=1,chnr;

	while(fgets(s,20,fin)!=NULL) // continui citirea din fisier
	{
		current=(struct node*)malloc(sizeof(struct node));//iau un noi pointer si pe acela il citesc.
		strcpy(current->info,s);
		current->next=NULL;
		current->prev=NULL;

		tail->next=current;
		current->prev=tail;
		tail=current;
		nrelem++;
	}

	sortlist(head);//sortez lista.

	tail->next=head;
	head->prev=tail;// o fac circulara.

	printf("Choose a number to counter whose is out of the game and 1 for clockwise or 2 for reverclockwise :\n");
	scanf("%d %d",&chnr,&pick);

	// am luat o variabala pick, ce inseamna 1 pt clockwise si 2 pentru reverclockwise se citeste de la tastatura
	// 1 inseamna ca incep de la head 2 inseamna ca citesc de la tail.
	//am pus head=functie ce rezulta faptul ca childgame e de timp struct node *.
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