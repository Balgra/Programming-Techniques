#include<stdio.h>
#include<stdlib.h>


enum animalss
{
	Insects=1,
	Birds=2,
	Mammals=3,
	Fishes=4
};
struct insects
{
	int legs,lifespan;
	int flag;
};

struct birds
{
	int flightspeed,winglength;
	char migration[100];
	int flag;
};

struct mammals
{
	int weight,hight;
	char foodtype[100];
	int flag;
};

struct fishes
{
	int weight,swimmingdepth,watersaltpercentage;
	int flag;
};

union animals
{
	struct insects insect;
	struct birds bird;
	struct mammals mammal;
	struct fishes fish;

};
/*
The system must
be able to add, delete, replace and lookup entries into the memory
database. The animal classes are described by 
(a) number of legs and life span for insects
(b) flight speed, wing length and migration habbits for birds
(c) weight, height and food type for mammals
(d) weight, swimming depth and water salt percentage for fishes*/

int main()
{

	union animals animal[100];
	int i=0,n=0,choice,index,replaceable;

	do
	{
		printf(" \nThis is the menu, give the objects \n");
		printf("'0' if you want to finish it \n");
		printf("'1' if you want to read an insect\n");
		printf("'2' if you want to read a bird \n");
		printf("'3' if you want to read a mammal\n");
		printf("'4' if you want to read a fish \n");
		printf("'5' to print all the animals \n");
		printf("'6' to delete a certain animal from an idex \n");
		printf("'7' to replace a certain animal with another \n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 0:
				printf("that was it folks \n");
				break;

			case 1:
				printf("To read an insect you must provide number of legs and lifespan and its number choice '1' \n");
				scanf("%d %d %d", &animal[i].insect.legs, &animal[i].insect.lifespan, &animal[i].insect.flag);
				//printf("%d %d %d \n", animal[i].insect.legs, animal[i].insect.lifespan, animal[i].insect.flag);
				break;

			case 2:
				printf("To read a bird you must provide flightspeed winglength where it migrates and its number choice '2' \n");
				scanf("%d %d %s %d", &animal[i].bird.flightspeed, &animal[i].bird.winglength, animal[i].bird.migration, &animal[i].bird.flag);
				//printf("%d %d %s %d \n", animal[i].bird.flightspeed, animal[i].bird.winglength, animal[i].bird.migration, animal[i].bird.flag);
				break;

			case 3:
				printf("To read a mammal you must provide weight, hight, foodtype and its number choice '3' \n ");
				scanf("%d %d %s %d", &animal[i].mammal.weight, &animal[i].mammal.hight, animal[i].mammal.foodtype, &animal[i].mammal.flag);
				//printf("%d %d %s %d", animal[i].mammal.weight, animal[i].mammal.hight, animal[i].mammal.foodtype, animal[i].mammal.flag);
				break;

			case 4:
				printf("To read a fish you must provide weight watersaltpercentage swimmingdepth and its number choice '4' \n");
				scanf("%d %d %d %d", &animal[i].fish.weight, &animal[i].fish.watersaltpercentage, &animal[i].fish.swimmingdepth, &animal[i].fish.flag);
				break;

			case 5:
				for(i=0;i<n;i++)
				{
					if(Insects==animal[i].insect.flag)
					{
						printf("The insect: Number of legs: %d and it lifespan: %d  \n",animal[i].insect.legs,animal[i].insect.lifespan);
					}
					if(Birds==animal[i].bird.flag)
					{
						printf("The bird with: Flightspeed: %d Winglength: %d And where she migrates: %s \n",animal[i].bird.flightspeed, animal[i].bird.winglength, animal[i].bird.migration);
					}
					if(Mammals==animal[i].mammal.flag)
					{
						printf("The mammal: The weight: %d The hight: %d It food type: %s \n",animal[i].mammal.weight,animal[i].mammal.hight, animal[i].mammal.foodtype);
					}
					if(Fishes==animal[i].fish.flag)
					{
						printf("The fish: The weight: %d The Water salt percentage: %d percentage Its maximum swimmingdepth: %d  \n", animal[i].fish.weight, animal[i].fish.watersaltpercentage, animal[i].fish.swimmingdepth);
					}

				}
				break;

			case 6:
				printf("which animal form which index you want to delete? Plese give me the index from 0 to %d \n",(n-1));
				scanf("%d", &index);
				for(i=index;i<n-1;i++)
				{
					animal[i]=animal[i+1];
				}
				n--;
				break;

			case 7:
					
					printf("which animal from which index you want to replace? Please give me the index from 0 to %d \n", (n-1));
					scanf("%d", &index);
					printf("with which kind of animal you want to be replace it? '1' insect, '2' brid '3' mammal '4' fish \n");
					scanf("%d", &replaceable);
					if(Insects==replaceable)
					{	
						printf("To read an insect you must provide number of legs and lifespan and its number choice '1' \n");
						scanf("%d %d %d", &animal[index].insect.legs, &animal[index].insect.lifespan, &animal[index].insect.flag);
					}
					if(Birds==replaceable)
					{
						printf("To read a bird you must provide flightspeed winglength where it migrates and its number choice '2' \n");
						scanf("%d %d %s %d", &animal[index].bird.flightspeed, &animal[index].bird.winglength, animal[index].bird.migration, &animal[index].bird.flag);

					}
					if(Mammals==replaceable)
					{
						printf("To read a mammal you must provide weight, hight, foodtype and its number choice '3' \n ");
						scanf("%d %d %s %d", &animal[index].mammal.weight, &animal[index].mammal.hight, animal[index].mammal.foodtype, &animal[index].mammal.flag);
					}
					if(Fishes==replaceable)
					{
						printf("To read a fish you must provide weight watersaltpercentage swimmingdepth and its number choice '4' \n");
						scanf("%d %d %d %d", &animal[index].fish.weight, &animal[index].fish.watersaltpercentage, &animal[index].fish.swimmingdepth, &animal[index].fish.flag);
					}
					break;

		}
			if(choice==1 || choice ==2 || choice==3 || choice==4)
			{
				i++;
				n++;
			}


	}while(choice!=0);

	return 0;

}