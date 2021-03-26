#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>

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
}