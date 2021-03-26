/*
 * Solves the same problem but with the second Greedy strategy. 
 */
#include <stdio.h>
#include <stdlib.h>

int mycmp(const void *a, const void *b) {
  return *((double *) b) - *((double *) a);
}

int main(void) {
  double x[] = { -10.1, 5.2, -3.33, 2, 7.1, -4.543, 8.103 };
  int N = 7;
  double y[100];
  int k, i;
  double chosen_x, sum;
  k = 0;
  sum = 0;
  qsort(x, N, sizeof(double), &mycmp);
  for (i = 0; (i < N) && (x[i] > 0); i++) {
    chosen_x = x[i];
    y[k++] = chosen_x;
    sum += chosen_x;
  }
  printf("%d chosen elements:", k);
  for (i = 0; i < k; i++)
    printf(" %g", y[i]);
  printf("\n");
  printf("Sum: %g.\n", sum);
  return 0;
}
