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
