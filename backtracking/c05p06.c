/*
 * c05p06.c - Chapter 05, Program 06
 * 
 * Backtracking solution to the Eight Queens problem. 
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * The size of the chess board. 
 */
#define N 8

/*
 * Special value used for marking a row which does not
 * contain any queen. 
 */
#define INVALID -1

int main(void)
{
  /*
   * c[k] stores the column where the queen in row k is
   * placed. 
   */
  int c[N];

  int k, i, can_continue, attacks;

  /*
   * We keep track of the number of solutions found. 
   */
  int count = 0;

  /*
   * Initially we don't have any queen placed on any row. 
   */
  for (i = 0; i < N; i++)
    c[i] = INVALID;

  /*
   * k shows the current row where we are trying to place 
   * a queen. 
   */
  k = 0;

  /*
   * As long as k stays above 0, we need to place the
   * queen on row k. When k goes below 0, it means we
   * have exhausted the entire search space and we can
   * stop. 
   */
  while (k >= 0) {
    /*
     * Choose values from the set S[k] and for each value 
     * evaluate the "Continue" function (implemented
     * here, not in separate function). 
     */
    do {
      /*
       * If element c[k] is INVALID, it means we have not 
       * tried to place a queen on this row k. We start
       * with the first column. 
       */
      if (c[k] == INVALID)
	c[k] = 0;
      /*
       * Otherwise we continue from the last column where 
       * we tried to place the queen. 
       */
      else
	c[k]++;

      /*
       * If we are still on the board, we start
       * evaluating "Continue". 
       */
      if (c[k] < N) {
	/*
	 * We check if the newly placed queen on this row 
	 * k attacks any queen placed on rows smaller
	 * than k. 
	 */
	attacks = 0;
	for (i = 0; !attacks && (i < k); i++) {
	  /*
	   * Check if queens i and k attack each other on 
	   * column. 
	   */
	  if (c[i] == c[k])
	    attacks = 1;

	  /*
	   * Check if queens i and k attack each other on 
	   * diagonals. 
	   */
	  else if (abs(i - k) == abs(c[i] - c[k]))
	    attacks = 1;
	}

	/*
	 * "Continue" return true if the new queen does
	 * not attack any previously placed queen. 
	 */
	can_continue = !attacks;
      }

      /*
       * Off the board there is no chance for a solution. 
       */
      else
	can_continue = 0;
    }
    while (!can_continue && (c[k] < N));
    /*
     * We will stop the loop above either when we find an 
     * element for which "Continue" returns true, either
     * when there is nothing left to choose from S[k]. 
     */


    /*
     * If "Continue" returned true, we consider the queen 
     * placed and we move on. 
     */
    if (can_continue) {
      /*
       * If we placed all queens, then we have a solution 
       * to the problem. There is no need to evaluate the 
       * "Solution" function, because the "Continue"
       * functions guarantee that the solution is
       * correct. 
       */
      if (k == N - 1) {
	for (i = 0; i < N; i++)
	  printf("%d ", c[i]);
	printf("\n");
	count++;
      }

      /*
       * If we still have queens to place, we move ahead
       * to the next queen. 
       */
      else
	k++;
    }

    /*
     * If "Continue" returned false, it means we could
     * not find another way of placing the queen on row
     * k. This we remove the queen from the row (set c[k] 
     * to INVALID) and we step back and continue with the 
     * previous queen (k--). 
     */
    else {
      c[k] = INVALID;
      k--;
    }
  }

  printf("%d solutions.\n", count);
  return 0;
}
