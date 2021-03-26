#include<stdio.h>
#include<stdlib.h>


/*struct snode {
char name [ 10] ;
char address [ 20 ] ;
float income ;
};

union unode {
char name [ 10 ] ;
char address [ 20 ] ;
float income ;
};

struct{
	unsigned int age : 3;
	unsigned int dayWeek : 3;
	unsigned int flagValid : 1;

}Info;

enum cardsuit
{
	CLUBS=1,
	DIAMOND=2,
	HEARTS=3,
	SPADES=4
}custom_decks[52];


int main()
{
	//printf("%ld \n",sizeof(struct snode));

	//printf("%ld \n",sizeof(union unode));

	union unode *u2;

	u2=(union unode *) malloc(sizeof(union unode));
	if(u2==NULL)
	{
		printf("Failed");
	}
	else
	{
		u2->income=3.14;
		u2->name="0x0"; u2->name[0]="0x0";
		u2->address="0";
	}
	printf("%f %p %s",u2->income,u2->name,u2->address);
	free(u2);


	return 0;


	unsigned int aux;
	scanf("%u",&aux);
	if(aux==0)
	{
		Info.flagValid = 0;
	}
	else
	{
		Info.flagValid=1;
	}
	if(aux>1)//why is it like this?
	{
		fprintf(stderr,"sir you should be more careful with the input \n");
	}
	custom_decks[0]=DIAMOND;
	printf("%d \n",custom_decks[0]); // how to use enum

*/
// problema 2;
enum shapes{
	Circle=1,
	Rectangle=2,
	Triangle=3
};

struct points
{
	int x;
	int y;
};

struct circles
{
	struct points r,o;
};

struct rectangles
{
	struct points a,b,c,d;
};

struct triangles
{
	struct points a,b,c;
};

union structures
{
	struct triangles triangle;
	struct rectangles rectangle;
	struct circles circle;
	unsigned flag;
};
int main()
{
	union structures structures[100];
	int i=0,n=1,choice,v[100];

// i have to mention somethings, i used v[100] for the first numbers i read exe: traingle/circle/rectangle.a.x because when i use
//structures[i].flag it overwrittens the first number i read,so i used this vector to anticipate that mistake, and it works,
//i've tried to put ifs and really tried all the variations but it didn;t work, so i had to use this simple, yet super useful vector.

	do
	{
		printf(" \nThis is the menu, give the objects \n");
		printf("'0' if you want to finish it \n");
		printf("'1' if you want to read a circle\n");
		printf("'2' if you want to read a rectanble \n");
		printf("'3' if you want to read a traingle\n");
		printf("'4' if you want to print all the objects read \n");
		scanf("%d",&choice);
		/*if((choice>=1) && (choice<=3))
		{
			printf(" the choice %d \n",choice);
			structures[i].flag=choice;
		}*/

		switch(choice)
		{
			case 0:
				printf("that was it friend !");
				break;
			case 1:	// here is for circle
				printf("the coordinates of the circle (4 numbers) ");
				scanf(" %d %d %d %d", &structures[i].circle.r.x, &structures[i].circle.r.y, &structures[i].circle.o.x, &structures[i].circle.o.y);
				v[i]=structures[i].circle.r.x;
				structures[i].flag=choice;
				break;
			case 2://here is a rectangle
				printf("the coordinates of the rectangle (8 numbers) ");
				scanf(" %d %d %d %d %d %d %d %d", &structures[i].rectangle.a.x, &structures[i].rectangle.a.y, &structures[i].rectangle.b.x, &structures[i].rectangle.b.y, &structures[i].rectangle.c.x, &structures[i].rectangle.c.y, &structures[i].rectangle.d.x, &structures[i].rectangle.d.y);
				v[i]=structures[i].rectangle.a.x;
				structures[i].flag=choice;
				break;
			case 3://this is for triangle
				printf("the coordinates of the trinagle (6 numbers) ");
				scanf(" %d %d %d %d %d %d", &structures[i].triangle.a.x, &structures[i].triangle.a.y, &structures[i].triangle.b.x, &structures[i].triangle.b.y, &structures[i].triangle.c.x, &structures[i].triangle.c.y);
				v[i]=structures[i].triangle.a.x;
				structures[i].flag=choice;
				break;
			case 4 :
				for(i=0;i<n-1;i++)
				{

					if(structures[i].flag== Triangle)
					{
						printf("Triangle: (%d,%d) (%d,%d) (%d,%d) ", v[i], structures[i].triangle.a.y, structures[i].triangle.b.x, structures[i].triangle.b.y, structures[i].triangle.c.x, structures[i].triangle.c.y);
					}
					if(structures[i].flag== Circle)
					{
						printf("Circle: (%d,%d) (%d,%d) ",v[i],structures[i].circle.r.y,structures[i].circle.o.x,structures[i].circle.o.y);
					}
					if(structures[i].flag== Rectangle)
					{
						printf("Rectangle:(%d,%d) (%d,%d) (%d,%d) (%d,%d) ",v[i],structures[i].rectangle.a.y,structures[i].rectangle.b.x,structures[i].rectangle.b.y,structures[i].rectangle.c.x,structures[i].rectangle.c.y,structures[i].rectangle.d.x,structures[i].rectangle.d.y);
					}
				}
				break;

		}
		i++;n++;


    }while(choice!=0);

	return 0;
}