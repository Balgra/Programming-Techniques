// functie merge sort;
/*#include<stdio.h>
#include<stdlib.h>
void sorting(int v[],int n)
{
	int i,j;
	int aux;
	for(i=1;i<n;i++)
	{
		aux=v[i];
		for(j=i-1;j>=0 && aux<v[j];j--)
		{
			v[j+1]=v[j];
		}
			v[j+1]=aux;
	}


}*/
/*int main()
{
	int v[100], n=10;
	for(int i=0;i<=n;i++)
	{
		v[i]=rand()%1000;
		printf("%d ",v[i]);
	}
	printf("\n");
	sorting(v,n);
	for(int i=0;i<n;i++)
	{
		printf(" %d ",v[i]);
	}	
}*/

//problema 1;
/*#include<stdio.h>
#include<stdlib.h>

int cmp(const void *r1,const void *r2)
{
	int rw1=*(int *)r1;

	int rw2=*(int *)r2;

	return rw1-rw2;
}

int main()
{
	int v[100],i,n=15;

	for(i=0;i<n;i++)
	{
		v[i]=rand();;
	}

	qsort(v,n,sizeof(int),cmp);

	for(i=0;i<n;i++)
	{
		printf("%d \n",v[i]);
	}

	return 0;

} */

			/*case 1: sum();
                break;
            case 2: rest();
                break;
            case 3: printf("Quitting program!\n");
                exit(0);
                break;
            default: printf("Invalid choice!\n");
                break;
                */
 //problema 2
/*#include<stdio.h>
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
}*/
//problema 3
/*#include<stdio.h>
#include<stdlib.h>
int reverseBinarySearch(int min,int max)
{
	char s[5]="y";;
	int mid=(min+max)/2;
	//printf("is your number between %d %d ?",min,mid);
	//scanf("%s",s);
	while(min!=mid || max!=mid)
	{
		printf("is your number between %d %d ?",min,mid);
		scanf("%s",s);
		if(s[0]=='y')
		{
			reverseBinarySearch(min,mid);
		}
		else
			{
				if(s[0]=='n')
				{
					reverseBinarySearch(mid,max);
				}
				else
				{
					printf("wrong input");
					exit(-1);
				}
			}
	}
	return mid;

}
#include<stdio.h>
int main()
{
	int n;
	printf("Let me see if i have your favorite number in my library:");
	scanf("%d ",&n);
	if(n>=0 && n<=1000)
	{
		printf("%d",reverseBinarySearch(0,1000)); 
	}
	else
		printf("Sorry, your number is too large");

}*/
#include <stdio.h>
#include <stdlib.h>
void GuessNr(int nrtoguess)
{
    int guess; 
    
    do {
        scanf("%d", &guess);
        if (guess == nrtoguess)
         {
            printf("You guessed correctly,nice job \n");
            exit(-1);
        }

        if (guess < nrtoguess)
         {
            printf("Your guess is too low. Guess again. ");
        }

        if (guess > nrtoguess)
         { 
            printf("Your guess is too high. Guess again. ");
        }
    } while (1);

}
int main() {
    int nrtoguess =80;
    printf("I'm thinking of a number bettween 0 and 1000, guess my number! "); 
    GuessNr(nrtoguess);
}
//problema 4
/*#include<stdio.h>
#include<stdlib.h>

int mybinarySearch(int v[], int lft, int rgt, int nrcheck) 
{ 
    if (rgt >= lft) { 
        int mid = (lft + rgt) / 2; 
  
        if (v[mid] == nrcheck) 
            return mid; 
  
        if (v[mid] > nrcheck) 
            return mybinarySearch(v, lft, mid - 1, nrcheck); 
  
        return mybinarySearch(v, mid + 1, rgt, nrcheck); 
    } 
  	
  	printf("The number given can't be found in the array \n");
    exit(-1); 
} 
  
int main()
{
	int nrread=15,nrcheck,fan=1,i,j,k;
	int v[100];
	for(i=2;i<=nrread;i++)
	{
		fan=1;
		for(j=2;j<=i/2;j++)
		{
			if(i%j==0)
			{
				fan=0;
			}
		}
		if(fan==1)
		{
			v[k]=i;
			k++;
		}
	}
	k--;
	printf("Give a number to see if it's in the array ");
	scanf("%d",&nrcheck);
	printf("The position of the number %d is on %d ",nrcheck,mybinarySearch(v,0,k,nrcheck));
}*/
