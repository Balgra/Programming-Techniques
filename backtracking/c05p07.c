/*
 * c05p07.c - Chapter 05, Program 07
 * 
 * Recursive Backtracking solution to the Eight Queens
 * problem. 
 */

#include <stdio.h>
#include <stdlib.h>

#define N 8
#define INVALID -1

int count = 0;
int c[N];

void print_solution(void)
{
  int i;
  for (i = 0; i < N; i++)
    printf("%d ", c[i]);
  printf("\n");
  count++;
}

int can_continue(int k)
{
  int i, attacks;
  if (c[k] < N) {
    attacks = 0;
    for (i = 0; !attacks && (i < k); i++) {
      if (c[i] == c[k])
	attacks = 1;
      else if (abs(i - k) == abs(c[i] - c[k]))
	attacks = 1;
    }
    return !attacks;
  } else {
    return 0;
  }
}

void queens(int k)
{
  int i;
  for (i = 0; i < N; i++) {
    c[k] = i;		/* Place queen on row k in column 
			 * i. */
    if (can_continue(k)) {	/* If it does not attack
				 * other queens. */
      if (k < N - 1)
	queens(k + 1);	/* If there are queens left to
			 * place, move on to the next. */
      else
	print_solution();	/* If all queens were
				 * placed, print
				 * solution. */
    }
    c[k] = INVALID;	/* Remove queen from row k. */
  }
}

int main(void)
{
  queens(0);

  printf("%d solutions.\n", count);
  return 0;
}
