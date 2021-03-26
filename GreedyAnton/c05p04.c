/*
 * Divide and Conquer algorithm for determining the
 * minimum and the maximum values from an array of
 * numbers. 
 */
#include <stdio.h>

/*
 * We define the content of the array directly from the
 * code. Alternatively it can be read from an input file. 
 */
#define N 10
int x[] = { 10, 5, 23, -11, 4, 2, 0, -6, 66, 40 };

/*
 * We keep track of the total number of comparisons
 * performed. 
 */
int comp = 0;

/*
 * Function that finds the minimum and the maximum values 
 * from a sequence of the array. The sequence is
 * delimited by the indexes "left" and "right". The found 
 * values will be returned through the pointers "min" and 
 * "max". 
 */
void minmax(int left, int right, int *min, int *max)
{
  int middle, min_left, max_left, min_right, max_right;

  printf("Searching in sequence [%d..%d].\n", left,
	 right);

  /*
   * If we have a sequence of only one element, then the
   * element is both the minimum and the maximum. 
   */
  if (left == right)
    *min = *max = x[left];
  /*
   * If the sequence has two elements, we make a
   * comparison for deciding which is the minimum and
   * which is the maximum. 
   */
  else if (left == right - 1) {
    comp++;
    if (x[left] < x[right]) {
      *min = x[left];
      *max = x[right];
    } else {
      *min = x[right];
      *max = x[left];
    }
  }
  /*
   * If we have more than two numbers, then the problem
   * is too difficult to solve directly. We split it in
   * two subproblems. 
   */
  else {
    /*
     * Split the problem. 
     */
    middle = (left + right) / 2;
    minmax(left, middle, &min_left, &max_left);
    minmax(middle + 1, right, &min_right, &max_right);

    /*
     * Combine solutions to subproblems. One comparison
     * for the global minimum and one comparison for the
     * global maximum. 
     */
    comp++;
    if (min_left < min_right)
      *min = min_left;
    else
      *min = min_right;
    comp++;
    if (max_left > max_right)
      *max = max_left;
    else
      *max = max_right;
  }
}

int main(void)
{
  int min, max;
  int i;

  /*
   * Print the array of numbers. 
   */
  printf("We have %d numbers.\n", N);
  for (i = 0; i < N; i++)
    printf("%d ", x[i]);
  printf("\n\n");

  /*
   * Call the recursive function. 
   */
  minmax(0, N - 1, &min, &max);

  /*
   * Print the results. 
   */
  printf("\n");
  printf("Minimum is %d.\n", min);
  printf("Maximum is %d.\n", max);
  printf("Number of comparisons performed: %d.\n", comp);

  return 0;
}
