#include<stdio.h>
#include<stdlib.h>

enum stars
{
	Sequencestar=1,
	Binarystar=2,
	Variablelightstar=3
};

struct Sequence_stars
{
	int age;
	char color[13];
};

struct Binary_stars
{
	char point[20];
	int radius1, radius2;
};

struct Varlight_stars
{
	int lowlumi, highlumi, lightperi;
};

struct Namestar
{
	char name[100];
};

union Allstars
{
	struct Sequence_stars seqstars;
	struct Binary_stars binarstars;
	struct Varlight_stars varstars;
	struct Namestar namestar;

};

int main()
{
	union Allstars stars[100];
	int choice;
	int i=0;

	do
	{
		printf(" \nThis is the menu, give the objects \n");
		printf("'0' if you want to finish it \n");
		printf("'1' if you want to read a Sequence star\n");
		printf("'2' if you want to read a Binary star \n");
		printf("'3' if you want to read a Variable light star\n");
		scanf("%d",&choice);


		switch(choice)
		{
			case 0:
			
				printf("that's all for today folks  \n");
				break;
			
			case 1:

				printf("To read a Sequence star you need a name, an age between 1 and 4 and a color of maximum 12 charachers \n");
				scanf("%s",stars[i].namestar.name);
				printf("Sequence star : The name of the star: %s ",stars[i].namestar.name);
				scanf(" %d %13s", &stars[i].seqstars.age, stars[i].seqstars.color);
				printf("The age of the star: %d The color of the star: %s \n", stars[i].seqstars.age, stars[i].seqstars.color);
				i++;
				break;

			case 2:

				printf("To read a binary star you need a name, a point name, and 2 radiuses \n");
				scanf("%s",stars[i].namestar.name);
				printf("Binarystar : The name of the star: %s ",stars[i].namestar.name);
				scanf(" %s %d %d", stars[i].binarstars.point, &stars[i].binarstars.radius1, &stars[i].binarstars.radius2);
				printf("The name of the points %s Its first radius %d Its second radius %d \n",stars[i].binarstars.point, stars[i].binarstars.radius1, stars[i].binarstars.radius2);
				i++;
				break;

			case 3:

				scanf("%s",stars[i].namestar.name);
				printf("Variable light star : The name of the star: %s ",stars[i].namestar.name);
				printf("To read a variable light star you need a name, its lowest luminosity, highest luminosity and light periodicity measured in earth days \n");
				scanf(" %d %d %d", &stars[i].varstars.lowlumi, &stars[i].varstars.highlumi, &stars[i].varstars.lightperi);
				printf("The lowest luminosity %d The highest luminosity %d The light period measured in Earth days %d \n",stars[i].varstars.lowlumi, stars[i].varstars.highlumi, stars[i].varstars.lightperi);
				i++;
				break;

			
		}


	}while(choice!=0);

	return 0;
}