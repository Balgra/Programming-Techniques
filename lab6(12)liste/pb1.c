#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;

	struct node *next;
	struct node *prev;
};

struct node *createnode(int info)
{
	struct node *p=NULL;

	p=(struct node *)malloc(sizeof(struct node));
   	if(p==NULL)
	{
		printf("teapa cumetre");
		exit(-1);
	}
	p->info=info;
	p->next=NULL;
	return p;
}

void printlists(struct node *n)
{
	while(n!=NULL)
	{
		printf("%d %p %p \n",n->info,n->prev,n->next);
		n=n->next;

	}
}

struct node *Createinreverse(struct node *n, int cnt)
{
	struct node *current, *inc, *sf, *p;
	
		current=(struct node*)malloc(sizeof(struct node));
		current->info=n->info;
		current->next=NULL;
		current->prev=NULL;
		inc=current;
		sf=current;
		p=current;

	for(int i=1;i<cnt;i++)
	{
		n=n->prev;
		current=(struct node*)malloc(sizeof(struct node));
		current->info=n->info;
		current->next=NULL;
		current->prev=NULL;

		sf->next=current;
		sf=sf->next;
		sf->prev=p;
		p=sf;

	}

	return inc;

}

int main()
{
	int n;
	printf("cati de multi pointer doresti in lista? \n");
	scanf("%d",&n);

	struct node *head, *current,*tail, *fct;

	current=(struct node*)malloc(sizeof(struct current*));
	current->info=112;
	current->next=NULL;
	current->prev=NULL;

	head=current;
	tail=current;
	struct node*p;
	p=current;

	for(int i=1;i<=n-1;i++)
	{
		tail->next=createnode(i);
		tail=tail->next;
		tail->prev=p;
		p=tail;
	}

	printf("From the start to be end: \n");
	printlists(head);


	printf("\n");
	printf("From the end to the start: \n");
	fct=Createinreverse(tail,n);

	printlists(fct);

	return 0;

}