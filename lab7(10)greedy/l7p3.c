#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


void SwapChar(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  
  /*
  01=10 174 12=21 152 23=32 393 43=34 388 
  02=20 315 13=31 544 24=42 449
  03=30 634 14=41 595
  04=40 544
  */
int v[100];
int min=999999;
void PermuteChar(char *a, int l, int r) 
{ 
   int i,j=0;
   if (l == r) 
   {
    v[j]=0;
     printf("the route is %s ", a); 
     for(i=0;i<5;i++)
     {
        if((a[i]=='0' && a[i+1]=='1')|| (a[i]=='1' && a[i+1]=='0'))
         {
          v[j]=v[j]+174;
         }
         if((a[i]=='0' && a[i+1]=='2')|| (a[i]=='2' && a[i+1]=='0'))
         {
          v[j]=v[j]+315;
         }
         if((a[i]=='0' && a[i+1]=='3')|| (a[i]=='3' && a[i+1]=='0'))
         {
          v[j]=v[j]+634;
         }
         if((a[i]=='0' && a[i+1]=='4')|| (a[i]=='4' && a[i+1]=='0'))
         {
          v[j]=v[j]+544;
         }
         if((a[i]=='1' && a[i+1]=='2')|| (a[i]=='2' && a[i+1]=='1'))
         {
          v[j]=v[j]+152;
         }
         if((a[i]=='1' && a[i+1]=='3')|| (a[i]=='3' && a[i+1]=='1'))
         {
          v[j]=v[j]+544;
         }
          if((a[i]=='1' && a[i+1]=='4')|| (a[i]=='4' && a[i+1]=='1'))
         {
          v[j]=v[j]+595;
         }
          if((a[i]=='2' && a[i+1]=='3')|| (a[i]=='3' && a[i+1]=='2'))
         {
          v[j]=v[j]+393;
         }
          if((a[i]=='2' && a[i+1]=='4')|| (a[i]=='4' && a[i+1]=='2'))
         {
          v[j]=v[j]+499;
         }
          if((a[i]=='4' && a[i+1]=='3')|| (a[i]=='3' && a[i+1]=='4'))
         {
          v[j]=v[j]+388;
         }
     }

     printf("and the length %d \n",v[j]);
     if(a[0]=='1')
     {
        if(v[j]<min)
        {
          min=v[j];
        }
     }
     j++;

   }
   else
   { 
       for (i = l; i <= r; i++) 
       { 
          SwapChar((a+l), (a+i)); 
          PermuteChar(a, l+1, r); 
          SwapChar((a+l), (a+i)); 
       } 
   } 
} 
  

int main() 
{ 
    char str[] = "01234"; 

    int n = strlen(str); 
    printf("0-Timisoara, 1-Oradea, 2-Cluj-Napoca, 3-Iasi, 4-Bucuresti \n");
    PermuteChar(str, 0, n-1); 

    printf("And the minimum route starting with Oradea (1) is %d \n",min);
    return 0; 
}