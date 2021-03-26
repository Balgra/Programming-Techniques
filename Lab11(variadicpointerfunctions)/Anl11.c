/*#include<stdio.h>

int sum(int a,int b)
{
	return a+b;
}

int prod(int a, int b)
{
	return a*b;
}

typedef struct ops
{
	int (*oper)(int a, int b);
	int res;
	int a,b;
}OPS;

int main()
{
	int (*operation)(int a, int b);
	int a=2,b=4;

	operation=&sum;

	printf("%d \n",operation(a,b));

	operation=&prod;

	printf("%d \n",operation(a,b));


	OPS varstruct;

	varstruct.a=2;varstruct.b=3;

	varstruct.oper=&sum;

	varstruct.res=(*varstruct.oper)(varstruct.a,varstruct.b);

	printf("%d %d ",varstruct.oper(varstruct.a,varstruct.b),varstruct.res);



}*//*
//problema 1;
#include <stdio.h>
#include <math.h>
#define N 5
struct gshape
{
    int type;
    int ID;
    union {
        struct
        {
            float radius;
            float x, y;
        } circle;
        struct
        {
            float x1, y1, x2, y2, x3, y3;
        } triangle;
        struct
        {
            float x1, y1;
            float x4, y4;
        } rectangle;
    } gshape;

    void (*read_gshape)(struct gshape *gs);
    void (*write_gshape)(struct gshape *gs);
    void (*area)(struct gshape *gs);
};

void read_circle(struct gshape *gs)
{
    scanf("%f ", &(gs->gshape.circle.radius));
    scanf("%f ", &(gs->gshape.circle.x));
    scanf("%f ", &(gs->gshape.circle.x));
}
void write_circle(struct gshape *gs)
{
    printf(" %f %f %f", (gs->gshape.circle.x), (gs->gshape.circle.y), (gs->gshape.circle.radius));
}
void read_triangle(struct gshape *gs)
{
    scanf(" %f %f %f %f %f %f ", &(gs->gshape.triangle.x1),&(gs->gshape.triangle.y1), &( gs->gshape.triangle.x2),&( gs->gshape.triangle.y2), &(gs->gshape.triangle.x3),&(gs->gshape.triangle.y3));
}
void write_triangle(struct gshape *gs)
{
    printf("The Triangle looks like this (% f ,% f ) (% f ,% f ) , (% f ,% f )\n ", gs->gshape.triangle.x1,gs->gshape.triangle.y1, gs->gshape.triangle.x2,gs->gshape.triangle.y2, gs->gshape.triangle.x3,gs->gshape.triangle.y3);
}
void read_rectangle(struct gshape *gs)
{
    printf("Reading the rectangle :\n ");
    scanf(" %f %f %f %f", &(gs->gshape.rectangle.x1), &(gs->gshape.rectangle.y1), &(gs->gshape.rectangle.x4), &(gs->gshape.rectangle.y4));
}
void write_rectangle(struct gshape *gs)
{
    printf(" %f %f %f %f", gs->gshape.rectangle.x1, gs->gshape.rectangle.y1, gs->gshape.rectangle.x4, gs->gshape.rectangle.y4);
}
void area_circle(struct gshape *gs)
{
    printf("The Circle area: %f\n", 3.14 * gs->gshape.circle.radius * gs->gshape.circle.radius);
}
float length(int x1, int y1, int x2, int y2)
{
     return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
void area_triangle(struct gshape *gs)
{
     float A, B, C, Perim;
     A = length(gs->gshape.triangle.x1, gs->gshape.triangle.x2, gs->gshape.triangle.y1, gs->gshape.triangle.y2);
     B = length(gs->gshape.triangle.x2, gs->gshape.triangle.x3, gs->gshape.triangle.y2, gs->gshape.triangle.y3);
     C = length(gs->gshape.triangle.x3, gs->gshape.triangle.x1, gs->gshape.triangle.y3, gs->gshape.triangle.y1);
     Perim = (A + B + C)/3.0;
     float area = sqrt(Perim*(Perim-A)*(Perim-B)*(Perim-C));
     printf("Triangle area: %f \n", area);
}
void area_rectangle(struct gshape *gs)
{
    int x, y;
    x = gs->gshape.rectangle.x1;
    y = gs->gshape.rectangle.y4;
    printf("Rectangle area: %f\n", length(x,y,gs->gshape.rectangle.x1,gs->gshape.rectangle.y1)*
                                    length(x,y,gs->gshape.rectangle.x4, gs->gshape.rectangle.y4));
}
int main(void)
{
    int i, type;
    struct gshape gs[N];
    printf("Initializing the geometric shapes collection:\n ");

    for (i = 0; i < N; i++)
    {
        do
        {
            printf("Shape ID %d : ", i);
            printf("What type of shape is it ? (0= circle, 1= triangle , 2= rectangle) \n");
            scanf(" %d", &type);
            gs[i].type = type;
            gs[i].ID = i;
            switch (gs[i].type)
            {
            	case 0:
            
               	 gs[i].read_gshape = &read_circle;
               	 gs[i].write_gshape = &write_circle;
               	 gs[i].area = &area_circle;
               	 gs[i].read_gshape(gs+i);
              	 break;
            
            	case 1:
            
               	 gs[i].read_gshape = &read_triangle;
               	 gs[i].write_gshape = &write_triangle;
               	 gs[i].area = &area_triangle;
               	 gs[i].read_gshape(gs+i);
                 break;
            
           	    case 2:
            
               	 gs[i].read_gshape = &read_rectangle;
               	 gs[i].write_gshape = &write_rectangle;
                 gs[i].area = &area_rectangle;
               	 gs[i].read_gshape(gs+i);
               	 break;
            
           		default:
            		printf("that was it folks!\n");

            }
        } while((gs[i].type != 0) && (gs[i].type != 1) && (gs[i].type != 2));
    }
     for (i = 0; i < N; i++)
         if (gs[i].type == 2)
         {
             gs[i].area(&gs[i]);
         }
    return 1;
}*/

  
#include <stdio.h>
#include <limits.h>
#include<stdarg.h>

void MaxMin(unsigned int n, ...)
{
    va_list arglist;    
    int min = 9999999;
    int max = -9999999;
    int connector,index;

    va_start(arglist, n);
    
    for(index = 0; index < n; index++)
    {
        connector = va_arg(arglist, int);

        if(connector > max)
        {
            max = connector;
        }
        if(connector < min)
        {
            min = connector;
        }
    }

    va_end(arglist);

    printf("The Minimum is: %d\n", min);
    printf("The Maximum is: %d\n", max);

}

int main()
{
    MaxMin(9, 3, 7, 1, 2, 8, 6,10,100,-1);

    return 0;
}
/*
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    double (*Mathfunct[])(double) = {sin, cos, sqrt, log, ceil, floor, fabs};
    
    char func[][10]={"sin", "cos", "sqrt", "log", "ceil", "floor", "fabs"};
    
    int op;
    do{

    	printf("Enter your option 0-sin, 1-cos, 2-sqrt, 3-log, 4-ceil, 5-floor, 6-fabs, 7-exit: ");
    	float nr;
     	scanf(" %d", &op);
     	if(op==7)
     	{
     		printf("that was it folks!\n");
     		exit(-1);
     	}
     	printf("Enter the number: \n");
     	scanf(" %f", &nr);

     	printf("Executing %s(%f)...\n Result: %f \n", func[op], nr, Mathfunct[op](nr));
      
       }while(op>=0 && op<=6);

    return 0;
}*/