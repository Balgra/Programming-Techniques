#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct nodessimple 
{
	int info;
	struct nodessimple *next;

};

struct nodedouble 
{
	int info;
	struct nodedouble *next,*prev;
};

void printlist(struct nodessimple *n)
{	
	while(n!=NULL)
	{
		printf("%d ",n->info);
		n=n->next;
	}
	printf("\n");
}

void printlistd(struct nodedouble *n)
{
	while(n!=NULL)
	{
		printf("%d ",n->info);
		n=n->next;
	}
}

void splitlist(struct nodessimple *n,int nrelem)
{
	int index,counter=1;
	printf("The simple linked list will be split into 2 double linked list, give the index 0-%d the left side of the sll will not contain the pointer at the given index \n",nrelem-1);
	scanf("%d",&index);
	//here i construct 1st double linked list;
	printf("The first half of the simple linked list : \n");
	struct nodedouble *head, *tail, *current;

	head=(struct nodedouble*)malloc(sizeof(struct nodedouble));
	head->info=n->info;
	head->next=NULL;
	head->prev=NULL;
	tail=head;
	current=head;
	n=n->next;

	while(index!=counter)
	{
		current=(struct nodedouble*)malloc(sizeof(struct nodedouble));
		current->info=n->info;
		current->next=NULL;
		current->prev=tail;

		tail->next=current;
		tail=current;
		n=n->next;
		counter++;
	}

	printlistd(head);


	printf("\n");
	printf("the second half of the \n");
	struct nodedouble *head1, *tail1, *current1;

	head1=(struct nodedouble*)malloc(sizeof(struct nodedouble));
	head1->info=n->info;
	head1->next=NULL;
	head1->prev=NULL;
	tail1=head1;
	current1=head1;
	n=n->next;

	while(n!=NULL)
	{
		current1=(struct nodedouble*)malloc(sizeof(struct nodedouble));
		current1->info=n->info;
		current1->next=NULL;
		current1->prev=tail1;

		tail1->next=current1;
		tail1=current1;
		n=n->next;
	}

	printlistd(head1);

}

int main()
{
	int n;
	struct nodessimple *head, *tail, *current;

	head=(struct nodessimple*)malloc(sizeof(struct nodessimple));
	srand(time(NULL));
	head->info=rand()%100;
	head->next=NULL;

	tail=head;

	printf("how many pointers do you want in your list? \n");
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		current=(struct nodessimple*)malloc(sizeof(struct nodessimple));
		current->info=rand()%100;
		current->next=NULL;

		tail->next=current;
		tail=current;
	}

	printlist(head);


	splitlist(head,n);

}