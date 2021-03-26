
#include<stdio.h>
#include <math.h>
#include<stdlib.h>


typedef struct points
{
    float x,y;
}pointsofreference;

int nriter=5;

void kochtrg(int n,pointsofreference M, pointsofreference N)
{

   			pointsofreference P,Q,R;

            P.x=(2*M.x+N.x)/(float)3;
            P.y=(2*M.y+N.y)/(float)3;

            Q.x=(2*N.x+M.x)/(float)3;
            Q.y=(2*N.y+M.y)/(float)3;

        	R.x=(Q.x + P.x + sqrt(3)*(Q.y - P.y) )/(float)2;
        	R.y=(P.y + Q.y + sqrt(3)*(P.x - Q.x) )/(float)2;

    if(n==0)
    {
        printf("%f,%f %f,%f \n",M.x,M.y,N.x,N.y);
    }
    else
    {
        kochtrg(n-1,M,P);
        kochtrg(n-1,P,R);
        kochtrg(n-1,R,Q);
        kochtrg(n-1,Q,N);
    }
    
}
int main()
{
    pointsofreference M,N,C;

    N.x=600;
    N.y=800;
    C.x=1100;
    C.y=800;

    //how many iterations

    scanf("%d",&nriter);

    printf("<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"%d\" height=\"%d\" >\n", 1520, 1500);

    M.x= (C.x + N.x + sqrt(3)*(C.y - N.y) )/(float)2;
    M.y=(N.y + C.y + sqrt(3)*(N.x - C.x) )/(float)2;

    printf("<polyline points=\"%f,%f ",M.x,M.y);

  	kochtrg(nriter-1,M,C);
    kochtrg(nriter-1,C,N);
   	kochtrg(nriter-1,N,M);

    printf("%f,%f\" stroke=\"black\" stroke-width=\"4\" fill=\"blue\" />\n",M.x,M.y);

    
    printf("</svg>\n");
    return 0;

}