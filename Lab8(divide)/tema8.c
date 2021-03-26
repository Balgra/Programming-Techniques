//exe 1

#include<stdio.h>
#include<stdlib.h>

void SperCarpet(int nrinter, int Xcoord, int Ycoord, int width)
{
	if(nrinter==0)
	{
		return; // this is how to exit a void function.
	}

    printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"black\"/>\n", Xcoord, Ycoord, width, width);

    //For the middle section of each squear
    SperCarpet(nrinter-1,Xcoord - 2*width/3, Ycoord + width/3, width/3);//left middle part
    SperCarpet(nrinter-1,Xcoord + width + width/3, Ycoord+width/3, width/3);//right middle part 

    //For the top  section of each squear
    SperCarpet(nrinter-1,Xcoord + width/3, Ycoord - 2*width/3, width/3);//middle top
    SperCarpet(nrinter-1,Xcoord + width/3 - 2*width/3 - width/3, Ycoord - 2*width /3, width/3);// left top part
    SperCarpet(nrinter-1,Xcoord + width/3 + 2*width/3 + width/3, Ycoord - 2*width/3, width/3);//right top part

     //For the bottom  section of each squear
    SperCarpet(nrinter-1,Xcoord + width/3 - 2*width/3 - width/3, Ycoord + width + width/3, width/3);// left bottom part
    SperCarpet(nrinter-1,Xcoord + width/3 + 2*width/3 + width/3, Ycoord + width + width/3, width/3);//right bottom part
    SperCarpet(nrinter-1,Xcoord + width/3, Ycoord + width + width/3, width/3);// middle bottom part

}

int main()
{

    printf("<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"%d\" height=\"%d\" stroke=\"blue\" stroke-width=\"0.3\" >\n", 1920, 5000);

    //how many iterations should be in the svg file.
   int nrelem;
   scanf("%d",&nrelem);
   int  Xcoordstart=650;
   int  Ycoordstart=500;
   int  widthstart=350;

    SperCarpet(nrelem,Xcoordstart,Ycoordstart,widthstart);


    printf("</svg>");
}

//exe 2
/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Peakvalues(int vectors[], int first, int last)
{
    while (first < last)
    {
        int mid = (first + last) / 2;

        if ((vectors[mid - 1] <= vectors[mid] && vectors[mid] >= vectors[mid + 1]) || (vectors[mid - 1] >= vectors[mid] && vectors[mid] <= vectors[mid + 1]))
        {
            printf("%d ", vectors[mid]);

            Peakvalues(vectors,first,mid-1);

            Peakvalues(vectors,mid+1,last);


            first=last;
        }
        else 
        	if (vectors[mid] > vectors[mid + 1])
            {
            	last = mid-1;
            }
        	else
       		{
            	first = mid + 1;
        	}
    }
}

int main()
{
	printf("how many lines and collumns should the matrix have note that they are the same so read only a number \n");
    int nrelem,i,j;
    scanf("%d",&nrelem);

    int Matrix[20][20];
    srand(time(NULL));

    for( i=0; i<nrelem; i++)
    {
        for( j=0; j<nrelem; j++)
        {
            Matrix[i][j]=rand()%100;
        }
    }

    for( i=0; i<nrelem; i++)
        {
            for( j=0; j<nrelem; j++)
            {
                printf("%d ",Matrix[i][j]);
            }
            printf("\n");
        }

       printf("\n\nPeak values: ");

       //In the essence a 2d vector(a matrix) is a vector of vector, so if i send the matrix[i] i actually send
       //the adrees of the first element from the line i 
       // so i used the fact that a matrix is a vector of vectors by using peakvalues(matrix(i),0,nrelem);

    for( i=0 ; i<nrelem; i++)
    {

        if(Matrix[i][0] > Matrix[i][1] || Matrix[i][0] < Matrix[i][1])
        {
            printf("%d ",Matrix[i][0]);
        }
        if(Matrix[i][nrelem-1]>Matrix[i][nrelem-2]|| Matrix[i][nrelem-1] < Matrix[i][nrelem-2])
        {
            printf("%d ",Matrix[i][nrelem-1]);
        }

        Peakvalues(Matrix[i], 0, nrelem);
    }

    printf("\n");

    return 0;
}
*/
//exe 4

/*

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int x=100,y=0,n,nriterations=0;
int diskx[10], disky[10], diskwidth[10], diskheight[10];

void printtable()
{

	int i;
	y=y+250;
 printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"lime\" />\n",x,y,400,20);
 printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"lime\" />\n",x,y-180,20,190);
 printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"lime\" />\n",x+190,y-180,20,190);
 printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"lime\" />\n",x+380,y-180,20,190);
 for(i=0;i<n;i++)
 {
 	if(i==0)
 	{
 	 printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" /> \n",x-100+diskx[i],y-disky[i],diskwidth[i],diskheight[i],"indigo");
 	}
 	if(i==1)
 	{
 	 printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" /> \n",x-100+diskx[i],y-disky[i],diskwidth[i],diskheight[i],"magenta");
 	}
 	if(i==2)
 	{
 	 printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" /> \n",x-100+diskx[i],y-disky[i],diskwidth[i],diskheight[i],"blue");
 	}
 	if(i==3)
 	{
 	 printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" /> \n",x-100+diskx[i],y-disky[i],diskwidth[i],diskheight[i],"yellow");
 	}
 	if(i==4)
 	{
 	 printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" /> \n",x-100+diskx[i],y-disky[i],diskwidth[i],diskheight[i],"red");
 	}
 	if(i==5)
 	{
 		printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" /> \n",x-100+diskx[i],y-disky[i],diskwidth[i],diskheight[i],"black");
 	}
 }


}

void movedisks(int i,char initial_rod,char final_rod)
{
	nriterations++;
	if(nriterations==4 && n==2)
	{
		 printf("</svg>");
		exit(-1);
	}
	if(nriterations==8 && n==3)
	{
		 printf("</svg>");
		exit(-1);
	}
	if(nriterations==16 && n==4)
	{
		 printf("</svg>");
		exit(-1);
	}
	if(nriterations==32 && n==5)
	{
		 printf("</svg>");
		exit(-1);
	}
	if(nriterations==64 && n==6)
	{
		printf("</svg>");
		exit(-1);
	}
	if((initial_rod=='a' && final_rod=='b') || (initial_rod=='b' && final_rod=='c')) 
		{
			diskx[i]=diskx[i]+185;
		}
	else
		{
			if(initial_rod=='a' && final_rod=='c')
			{
				diskx[i]=diskx[i]+370;
			}
			else
			{
				if((initial_rod=='c' && final_rod=='b') || (initial_rod=='b' && final_rod=='a'))
				{
					diskx[i]=diskx[i]-185;
				}
				else
				{
					if(initial_rod=='c' && final_rod=='a')
					{
						diskx[i]=diskx[i]-370;
					}
				}
			}

		}
}


void TowerHanoi(int whdisk, char initial_rod, char final_rod, char interm_rod)
{

  if (whdisk>0) 
  {
    TowerHanoi(whdisk - 1, initial_rod, interm_rod, final_rod);
    printf("<text x=\"%d\" y=\"%d\" font-size=\"20\">the disk that moved %d</text>\n", x, y,whdisk);
    movedisks(n-whdisk-1,initial_rod,final_rod);
    printtable();
    TowerHanoi(whdisk - 1, interm_rod, final_rod, initial_rod);
   }

  else
  {
  	printf("<text x=\"%d\" y=\"%d\" font-size=\"20\">the disk that moved %d</text>\n", x, y,whdisk);
  	movedisks(n-whdisk-1,initial_rod,final_rod);
  	printtable();
  }
}

int main()
{
 

 //how many disks are there to be introduced

 scanf("%d", &n);


 // the width and height of the browser, it it n*5500 because the program can run for up to 6 disks.

 printf("<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"%d\" height=\"%d\" >\n", 1920, n*5500);
printf("<text x=\"90\" y=\"15\" fill=\"red\">This is the Inital ROD this is the Final ROD This is the Aux ROD</text>");
printf("<text x=\"%d\" y=\"%d\" font-size=\"20\">ndisks %d</text>\n", x, y,n);
 diskx[0]=105;
 disky[0]=70;
 diskheight[0]=10;
 diskwidth[0]=30;
 for(int i=1;i<n;i++)
 {
 	diskx[i]=diskx[i-1]-10;
 	disky[i]=disky[i-1]+25;
 	diskwidth[i]=diskwidth[i-1]+15;
 	diskheight[i]=diskheight[i-1]+5;
 }
 printtable();
 TowerHanoi(n, 'a', 'c', 'b');

 printf("</svg>");
 return 0;
}*/