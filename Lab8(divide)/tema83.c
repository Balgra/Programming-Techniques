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
    printf("<text x=\"%d\" y=\"%d\" font-size=\"20\">the disk that will move %d</text>\n", x, y,whdisk);
    movedisks(n-whdisk-1,initial_rod,final_rod);
    printtable();
    TowerHanoi(whdisk - 1, interm_rod, final_rod, initial_rod);
   }

  else
  {
  	printf("<text x=\"%d\" y=\"%d\" font-size=\"20\">the disk that will move %d</text>\n", x, y,whdisk);
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
}