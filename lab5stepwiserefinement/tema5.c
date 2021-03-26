#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int isRunning = 1;
int table[3][3];
int table1[3][3];
int table2[3][3];
int length=0;
int verif=1;


void printtable()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(table[i][j]==0)
			{
				table[i][j]=32;
				table1[i][j]=32;
				table2[i][j]=32;
			}
		}
	}

	printf("the first table: \n");
    printf("| %c | %c | %c |\n", (char)table[0][0], (char)table[0][1], (char)table[0][2]);
    printf("| %c | %c | %c |\n", (char)table[1][0], (char)table[1][1], (char)table[1][2]);
    printf("| %c | %c | %c |\n", (char)table[2][0], (char)table[2][1], (char)table[2][2]);

    printf("the second table: \n");
    printf("| %c | %c | %c |\n", (char)table1[0][0], (char)table1[0][1], (char)table1[0][2]);
    printf("| %c | %c | %c |\n", (char)table1[1][0], (char)table1[1][1], (char)table1[1][2]);
    printf("| %c | %c | %c |\n", (char)table1[2][0], (char)table1[2][1], (char)table1[2][2]);

    printf("the third table: \n");
    printf("| %c | %c | %c |\n", (char)table2[0][0], (char)table2[0][1], (char)table2[0][2]);
    printf("| %c | %c | %c |\n", (char)table2[1][0], (char)table2[1][1], (char)table2[1][2]);
    printf("| %c | %c | %c |\n", (char)table2[2][0], (char)table2[2][1], (char)table2[2][2]);

}

int verifyPosition(int x, int y,int table[3][3]) 
{

    if(table[x][y] == 32)
     {
     	return 1;
     }
    else 
    	{
    		return 0;
    	}
}

int verifyMatrix3d()
{
	int i;
	for(i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if((table[i][j] == table1[i][j] && table1[i][j] == table2[i][j]) && table[i][j] != 32)
				{
					return 1;
				}

		}
	}

	if((table[0][0] == table1[0][1] && table1[0][1] == table2[0][2]) && table[0][0] !=32)
	{
		return 1;
	}

	if((table[1][0] == table1[1][1] && table1[0][1] == table2[1][2]) && table[1][0] !=32)
	{
		return 1;
	}

	if((table[2][0] == table1[2][1] && table1[2][0] == table2[2][2]) && table[2][0] !=32)
	{
		return 1;
	}


	if((table[0][0] == table1[1][1] && table1[1][1] == table2[2][2]) && table[0][0] != 32)
	{
		return 1;
	}

	if((table[0][2] == table1[1][1] && table1[1][1] == table2[2][0]) && table[0][2] != 32)
	{
		return 1;
	}



	return 0;
}

int verifyMatrix(int table[3][3]) {

    int i;
    for(i = 0; i < 3; i++) {
        if((table[i][0] == table[i][1] && table[i][0] == table[i][2]) && table[i][0] != 32)
            return 1;
    }
    for(i = 0; i < 3; i++) 
    {
        if((table[0][i] == table[1][i] && table[0][i] == table[2][i]) && table[0][i] != 32)
            return 1;

    }

    if((table[0][0] == table[1][1] && table[0][0] == table[2][2]) && table[0][0] != 32) 
    	{
    		return 1;
    	}
    if((table[0][2] == table[1][1] && table[0][2] == table[2][0]) && table[0][2] != 32)
    	 {
    	 	return 1;
    	 }
    return 0;
}

int smartmoves(int table[][3],int flag)
{
	int aux=0;
	int i;
	if(table[1][1]== 32 && aux==0)
	{
		table[1][1]=48;
		flag=1;
		aux=1;
	}
	if(table1[1][1]== 32 && aux==0)
	{
		table1[1][1]=48;
		flag=1;
		aux=1;
	}
	if(table2[1][1]== 32 && aux==0)
	{
		table2[1][1]=48;
		flag=1;
		aux=1;
	}
	for(i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if((table[i][j] == table1[i][j] && table[i][j]==88) && table2[i][j] == 32 && aux==0)
				{
					table2[i][j]=48;
					aux=1;
					flag=1;
				}

			if((table[i][j] == table2[i][j] && table[i][j]==88) && table1[i][j] == 32 && aux==0)
			{
				table1[i][j]=48;
				aux=1;
				flag=1;
			}

			if((table1[i][j] == table2[i][j] && table1[i][j]==88) && table1[i][j] == 32 && aux==0)
			{
				table[i][j]=48;
				aux=1;
				flag=1;
			}

		}
	}

	//first line
	if(table[0][0]==table[0][1] && table[0][0]==88 && table[0][2]==32 && aux==0)
	{
		table[0][2]=48;
		aux=1;
		flag=1;
	}

	if(table[0][0]==table[0][2] && table[0][0]==88 && table[0][1]==32 && aux==0)
	{
		table[0][1]=48;
		aux=1;
		flag=1;
	}

	if(table[0][1]==table[0][2] && table[0][1]==88 && table[0][0]==32 && aux==0)
	{
		table[0][0]=48;
		aux=1;
		flag=1;

	}


	//for the first collumn
	if(table[0][0]==table[1][0] && table[0][0]==88 && table[2][0]==32 && aux==0)
	{
		table[2][0]=48;
		aux=1;flag=1;

	}

	if(table[0][0]==table[2][0] && table[0][0]==88 && table[1][0]==32 && aux==0)
	{
		table[1][0]=48;
		aux=1;flag=1;

	}

	if(table[1][0]==table[2][0] && table[1][0]==88 && table[0][0]==32 && aux==0)
	{
		table[0][0]=48;
		aux=1;flag=1;

	}
	
	//for the second line
	if(table[1][0]==table[1][1] && table[1][0]==88 && table[1][2]==32 && aux==0)
	{
		table[1][2]=48;
		aux=1;flag=1;

	}

	if(table[1][0]==table[1][2] && table[1][0]==88 && table[1][1]==32 && aux==0)
	{
		table[1][1]=48;
		aux=1;flag=1;

	}

	if(table[1][1]==table[1][2] && table[1][1]==88 && table[0][1]==32 && aux==0)
	{
		table[0][1]=48;
		aux=1;flag=1;

	}

	// for the second collumn 
	if(table[0][1]==table[1][1] && table[0][1]==88 && table[2][1]==32 && aux==0)
	{
		table[2][1]=48;
		aux=1;flag=1;

	}

	if(table[0][1]==table[2][1] && table[0][1]==88 && table[1][1]==32 && aux==0)
	{
		table[1][1]=48;
		aux=1;flag=1;

	}

	if(table[1][1]==table[2][1] && table[1][1]==88 && table[0][1]==32 && aux==0)
	{
		table[0][1]=48;
		aux=1;flag=1;

	}

	// for the third line

	if(table[2][0]==table[2][1] && table[2][0]==88 && table[2][2]==32 && aux==0)
	{
		table[2][2]=48;
		aux=1;flag=1;

	}

	if(table[2][0]==table[2][2] && table[2][0]==88 && table[2][1]==32 && aux==0)
	{
		table[2][1]=48;
		aux=1;flag=1;

	}

	if(table[2][1]==table[2][2] && table[2][1]==88 && table[2][0]==32 && aux==0)
	{
		table[2][0]=48;
		aux=1;flag=1;

	}

	//for the third collumn

	if(table[0][2]==table[1][2] && table[0][2]==88 && table[2][2]==32 && aux==0)
	{
		table[2][2]=48;
		aux=1;flag=1;

	}

	if(table[0][2]==table[2][2] && table[0][2]==88 && table[1][2]==32 && aux==0)
	{
		table[1][2]=48;
		aux=1;flag=1;

	}

	if(table[1][2]==table[2][2] && table[1][2]==88 && table[0][2]==32 && aux==0)
	{
		table[0][2]=48;
		aux=1;flag=1;

	}

	//principal diagonal
	if(table[0][0]==table[1][1] && table[1][1]==88 && table[2][2]==32 && aux==0)
	{
		table[2][2]=48;
		aux=1;flag=1;

	}
	if(table[0][0]==table[2][2] && table[0][0]==88 && table[1][1]==32 && aux==0)
	{
		table[1][1]=48;
		aux=1;flag=1;

	}
	if(table[1][1]==table[2][2] && table[1][1]==88 && table[0][0]==32 && aux==0)
	{
		table[0][0]=48;
		aux=1;flag=1;

	}

	//secondary diagonal
	if(table[0][2]==table[1][1] && table[0][2]==88 && table[2][0]==32 && aux==0)
	{
		table[2][0]=48;
		aux=1;flag=1;

	}
	if(table[0][2]==table[2][0] && table[0][2]==88 && table[1][1]==32 && aux==0)
	{
		table[1][1]=48;
		aux=1;flag=1;

	}
	if(table[1][1]==table[2][0] && table[2][0]==88 && table[0][2]==32 && aux==0)
	{
		table[0][2]=48;
		aux=1;flag=1;

	}

	return flag;
	
}
void movePlayer1() 
{
    int x, y,index;
    printf("\n");
    printf("On which table you want to put give a number from 1-3\n");
    scanf("%d",&index);
    printf("Jucatorul 1 trebuie sa introduca urmatoarea mutare alege 2 numere intre 1 si 3\n");
    printf("X = linia si Y = coloana introdusa\n");
    scanf("%d %d", &x, &y);
    printf("Ai introdus x = %d si y = %d\n", x, y);
    if(index==1)
    {
        if(verifyPosition(x - 1, y - 1,table)) 
        {	

            table[x - 1][y - 1] = 88;
            if(verifyMatrix(table) || verifyMatrix3d()) 
            {
                printf("Player-ul a castigat!!\n");
                printtable();
                exit(-1);
                isRunning = 0;
            }
             else 
            {
                printtable();
            }
        } 
        else 
        {
            printf("Pozitia este deja ocupata, introdu din nou datele");
            movePlayer1();
  		}
  	}
  		if(index==2)
  		{
       		 if(verifyPosition(x - 1, y - 1,table1)) 
       		{	

         	   table1[x - 1][y - 1]=88;
           	 if(verifyMatrix(table1) || verifyMatrix3d()) 
            	{
             	   printf("Player-ul a castigat!!\n");
              	  printtable();
              	  exit(-1);
               	 isRunning = 0;
           		 }
            	 else 
            	{
            	    printtable();
            	}
        	} 
        	else 
       		 {
         	   printf("Pozitia este deja ocupata, introdu din nou datele");
         	   movePlayer1();
  			}
  	}
  		if(index==3)
  		{
        if(verifyPosition(x - 1, y - 1,table2)) 
        {	

            table2[x - 1][y - 1]=88;
            if(verifyMatrix(table2) || verifyMatrix3d()) 
            {
                printf("Player-ul a castigat!!\n");
                printtable();
                exit(-1);
                isRunning = 0;
            }
             else 
            {
                printtable();
            }
        } 
        else 
        {
            printf("Pozitia este deja ocupata, introdu din nou datele");
            movePlayer1();
  		}
  	}
}

// the random function
int randomNumberGenerator(const int nMin, const int nMax, const int  nNumOfNumsToGenerate)
{
  int nRandonNumber = 0;
  for (int i = 0; i < nNumOfNumsToGenerate; i++)
  {
    nRandonNumber = rand()%(nMax-nMin) + nMin;
  }
  return nRandonNumber;
}
void movePlayer2Smart()
{
	int flag=0;
	flag=smartmoves(table,flag);
	if(flag!=1)
		{
			flag=smartmoves(table1,flag);
		}
	if(flag!=1)
		{
			flag=smartmoves(table2,flag);
		}

	if(flag==1)
	{
		printf("Playerul 2 a ales \n");
		printtable();
		if(verifyMatrix(table) || verifyMatrix3d()) 
   		 {
 	       printf("Computerul a castigat!!\n");
 	       printtable();
	  	   exit(-1);
 	 	   isRunning = 0;
  	 	 } 

	}
	if(flag==0)
	{
		 int x = randomNumberGenerator(0, 3, 1);
   		 int y = randomNumberGenerator(0, 3, 1);
   		 int layer=randomNumberGenerator(1, 4, 1);
   		 printf("layer= %d \n",layer);
   		 if(layer==1)
   		 {

   		 	while(!verifyPosition(x, y,table)) 
	   		 {
   	      	 	x = randomNumberGenerator(0, 3, 1);
    	  	 	y = randomNumberGenerator(0, 3, 1);
   	 		 }
   		 	printf("Playerul 2 a ales: \n");
   			table[x][y] = 48;
   			if(verifyMatrix(table) || verifyMatrix3d()) 
   			 {
 	      		 printf("Computerul a castigat!!\n");
 	      	 	printtable();
	  	  	 	exit(-1);
 	 	  		 isRunning = 0;
  	 		 } 
  	  		else
   	 		{
   	 			printtable();
   	 		}
   		 }
   		 if(layer==2)
   		 {

   		 	while(!verifyPosition(x, y,table1)) 
	   		 {
   	      	 	x = randomNumberGenerator(0, 3, 1);
    	  	 	y = randomNumberGenerator(0, 3, 1);
   	 		 }
   		 	printf("Playerul 2 a ales: \n");
   			table1[x][y] = 48;
   			if(verifyMatrix(table1) || verifyMatrix3d()) 
   			 {
 	      		 printf("Computerul a castigat!!\n");
 	      	 	printtable();
	  	  	 	exit(-1);
 	 	  		 isRunning = 0;
  	 		 } 
  	  		else
   	 		{
   	 			printtable();
   	 		}
   		 }
   		 if(layer==3)
   		 {

   		 	while(!verifyPosition(x, y,table2)) 
	   		 {
   	      	 	x = randomNumberGenerator(0, 3, 1);
    	  	 	y = randomNumberGenerator(0, 3, 1);
   	 		 }
   		 	printf("Playerul 2 a ales: \n");
   			table2[x][y] = 48;
   			if(verifyMatrix(table2) || verifyMatrix3d()) 
   			 {
 	      		 printf("Computerul a castigat!!\n");
 	      	 	printtable();
	  	  	 	exit(-1);
 	 	  		 isRunning = 0;
  	 		 } 
  	  		else
   	 		{
   	 			printtable();
   	 		}
   		 }
	}

}

int main()
{

    srand(time(NULL));  
    printtable();
    while(isRunning) 
    {
        movePlayer1();
        movePlayer2Smart();

    }
}