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