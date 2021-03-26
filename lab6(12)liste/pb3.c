#include<stdio.h>
#include<stdlib.h>
#include<time.h>


struct node
{
	int info;
	struct node *next;
};

int counter=0;
void printlist(struct node *n,int nrelem)
{
	counter=0;
	while(counter!=nrelem)
	{
		counter++;
		printf("%d ",n->info);
		n=n->next;
	}
	printf("\n");
}	

void removemiddle(struct node* n, int nrelem)
{
	int middle=0;
	struct node *current;
	current=n;
	if(nrelem % 2==0)
	{
		nrelem--;
	}

	while(middle!=nrelem/2-1)
	{
		middle++;
		current=current->next;
	}

	printf("The pointer that was cut of, because he was the middle, has the info %d and the address %p  \n",current->next->info,current->next->next);
	current->next=current->next->next;

	printlist(n,nrelem);

}

int main()
{
	srand(time(NULL));
	int n,i;
	struct node *head, *tail, *current;

	head=(struct node*)malloc(sizeof(struct node));
	head->info=rand()%100;
	head->next=NULL;

	tail=head;
	printf("How many pointer do you want in your list \n");
	scanf("%d",&n);

	for(i=1;i<=n-1;i++)
	{
		current=(struct node*)malloc(sizeof(struct node));
		current->info=rand()%100;
		current->next=NULL;

		tail->next=current;
		tail=current;	
	}
	tail->next=head;


	printlist(head,n);	

	removemiddle(head,n);

	free(head);free(tail);free(current);

	return 0;
}