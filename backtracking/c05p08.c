/*
 * c05p08.c - Chapter 05, Program 08
 * 
 * Recursive Backtracking solution for the Knight's Tour
 * problem. 
 */
#include <stdio.h>

/*
 * Size of the board. 
 */
#define N 5

/*
 * The eight possible moves that can be made by a knight. 
 */
int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int c[N * N][2];	/* The path of the knight on the
			 * board. An array of pairs of
			 * coordinates (line,column). */

int count = 0;		/* The number of paths found. */

void back(int step)
{
  int i, j, can_continue;

  /*
   * If the entire board is covered, print the path. 
   */
  if (step == N * N) {
    for (i = 0; i < step; i++)
      printf("(%d,%d) ", c[i][0], c[i][1]);
    printf("\n");
    count++;
  }
  /*
   * If there are still squares to cover, try to make
   * another move. 
   */
  else {
    /*
     * Try all eight possible moves of the knight. 
     */
    for (i = 0; i < 8; i++) {
      c[step][0] = c[step - 1][0] + dy[i];
      c[step][1] = c[step - 1][1] + dx[i];

      /*
       * Check if the move is valid. First condition is
       * to be on the board. 
       */
      if ((c[step][0] >= 0) && (c[step][0] < N) &&
	  (c[step][1] >= 0) && (c[step][1] < N)) {
	/*
	 * The second condition is to not have been in
	 * this square before. 
	 */
	can_continue = 1;
	for (j = 0; can_continue && (j < step); j++) {
	  if ((c[j][0] == c[step][0]) &&
	      (c[j][1] == c[step][1]))
	    can_continue = 0;
	}
	/*
	 * If the move is valid, remember it and continue 
	 * * to a next move. 
	 */
	if (can_continue)
	  back(step + 1);
      }
    }
  }
}

int main(void)
{
  int i, j;

  /*
   * Start from each square on the board and find paths
   * from it. 
   */
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      /*
       * The first move will be in square (i,j). 
       */
      c[0][0] = i;
      c[0][1] = j;
      /*
       * We invoke the recursive function to find the
       * next moves. 
       */
      back(1);
    }

  printf("%d paths.\n", count);
  return 0;
}
