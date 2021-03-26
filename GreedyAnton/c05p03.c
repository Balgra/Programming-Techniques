/*
 * Greedy solution for the Travelling Salesman Problem. 
 */
#include <stdio.h>
#include <stdlib.h>

#define N_MAX 30	/* Maximum number of points. */

/*
 * A big value to be used for initialization when
 * searching for the minimum value. 
 */
#define BIG_VALUE 10000

int n;			/* Number of points. */
int d[N_MAX][N_MAX];	/* Array with distances between
			 * points. */
int path[N_MAX];	/* Array that holds the path of
			 * the travelling salesman.
			 * Contains the indexes of the
			 * points, in the order they are
			 * visited. */
int visited[N_MAX];	/* Array that keeps track of
			 * visited points. visited[k]
			 * will be 1 if the point with
			 * index k was visited. */

/*
 * Function that chooses the next pair of points to be
 * added to the path. Receives as parameter the index of
 * the last visited point and computes the index of the
 * next point to visit, together with the distance
 * towards it. 
 */
void choose(int last, int *distance, int *next)
{
  int j;

  /*
   * We compute the minimum distance from the last
   * visited point towards a not yet visited point. 
   */
  *distance = BIG_VALUE;
  *next = -1;
  for (j = 0; j < n; j++)
    if (!visited[j])
    {
      if (d[last][j] < *distance)
       {
	          *distance = d[last][j];
	           *next = j;
       }
    }
}

int main(void)
{
  FILE *fin;
  int i, j, cost, min, next;

  /*
   * Read data from the input file. 
   */
  fin = fopen("c05p03.in", "rt");
  if (!fin) {
    printf("Error: cannot open input file.\n");
    exit(1);
  }
  fscanf(fin, "%d", &n);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      fscanf(fin, "%d", &(d[i][j]));

  /*
   * Print input data on the screen. 
   */
  printf("We have %d points.\n", n);
  printf("Distances between points are:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf("%d ", d[i][j]);
    printf("\n");
  }
  printf("\n");

  /*
   * The first visited point is number "0". The path
   * length is 0 for now. 
   */
  path[0] = 0;
  visited[0] = 1;
  for (i = 1; i < n; i++)
    visited[i] = 0;
  cost = 0;

  /*
   * Visit the rest of n-1 points. 
   */
  for (i = 0; i < n - 1; i++) {
    /*
     * Choose the next point to visit. 
     */
    choose(path[i], &min, &next);

    /*
     * Link the new point to the already built path. 
     */
    printf("We choose the road (%d, %d) of cost %d.\n",
	   path[i], next, min);
    path[i + 1] = next;
    visited[next] = 1;
    cost += min;
  }

  /*
   * Close the path back to the first point. 
   */
  path[n] = 0;
  cost += d[path[n - 1]][0];
  printf
      ("We choose the road (%d, %d) of cost %d.\n",
       path[n - 1], 0, d[path[n - 1]][0]);

  /*
   * Print the path on the screen. 
   */
  printf("\nThe path has total length %d and is:\n",
	 cost);
  for (i = 0; i <= n; i++)
    printf("%d ", path[i]);
  printf("\n");

  return 0;
}
