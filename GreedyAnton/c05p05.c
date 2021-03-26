/*
 * Divide and Conquer solution to the Towers of Hanoi
 * problem. 
 */
#include <stdio.h>

/*
 * Function that moves n disks from an initial rod to a
 * final rod, using an intermediate rod.  
 */
void hanoi(int n, char initial_rod, char final_rod,
	   char interm_rod)
{
  /*
   * If we have more than one disk to move, than the
   * problem is too complex and we decompose it in
   * subproblems. 
   */
  if (n > 1) {
    hanoi(n - 1, initial_rod, interm_rod, final_rod);
    printf("%c -> %c\n", initial_rod, final_rod);
    hanoi(n - 1, interm_rod, final_rod, initial_rod);
  }
  /*
   * If there is only one disk, then it is trivial to
   * move it. 
   */
  else
    printf("%c -> %c\n", initial_rod, final_rod);
}

int main(void)
{
  /*
   * Number of disks. 
   */
  int n;

  /*
   * Read the number of disks from the keyboard. 
   */
  printf("How many disks? ");
  scanf("%d", &n);

  /*
   * Call the recursive function. 
   */
  hanoi(n, 'a', 'b', 'c');

  return 0;
}
