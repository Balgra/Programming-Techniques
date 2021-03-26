/*
 * Given a set of real numbers, the program finds a subset so that the sum 
 * of the elements in the subset is maximal. The first Greedy strategy is
 * used. 
 */
#include <stdio.h>

double choose(double x[], int N) {
  static int idx = 0;
  return idx < N ? x[idx++] : 0;
}

int possible(double x) {
  return x > 0;
}

int main(void) {
  double x[] = { -10.1, 5.2, -3.33, 2, 7.1, -4.543, 8.103 };
  int N = 7;
  double y[100];
  int k, i;
  double chosen_x, sum;
  k = 0;
  sum = 0;
  for (i = 0; i < N; i++) {
    chosen_x = choose(x, N);
    if (possible(chosen_x)) {
      y[k++] = chosen_x;
      sum += chosen_x;
    }
  }
  printf("%d chosen elements:", k);
  for (i = 0; i < k; i++)
    printf(" %g", y[i]);
  printf("\n");
  printf("Sum: %g.\n", sum);
  return 0;
}
