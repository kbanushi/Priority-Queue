
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/********
 * file: heap_demo.c
 * desc: bare bones C implementation of fundamental heap 
 *        operations.
 *      Heaps are not "bundled" into a struct - they are
 *        just passed around with their size.
 *
 * compilation:  gcc heap_demo.c -o heap_demo
 *
 * usage:  ./heap_demo <N>
 *              (N defaults to 10)
 * behavior:  program generates a random data set of N
 *              doubles; makes a copy; invokes bottom-up
 *              build heap on one copy and top-down build-heap
 *              on the other.
 *
 *              These heaps are displayed layer-by-layer and
 *              then emptied by a sequence of N delete_min ops
 */

/*
 * precolate-up from position i
 */
void perc_up(double h[], int i){
  double x=h[i];
  int p;
  p=i/2;
  while(p > 0 && x < h[p]) {
    h[i]=h[p];
    i=p; p=i/2;
  }
  h[i]=x;
}


/*
 *  returns index of smallest child of root
 *     (if any).
 *      if root is a leaf, -1 is returned
 **/
int min_child_idx(double h[], int root, int n) {
  int left, right;

  left=2*root;
  right=left+1;
  if(left > n) return -1;
  if(left==n || h[left] < h[right])
    return left;
  return right;
}

/*
 * precolate-down from position i
 */
void perc_down(double h[], int i, int n){
  double x=h[i];
  int min_c;  // idx of small child
  min_c = min_child_idx(h, i, n);
  while(min_c != -1 && h[min_c] < x) {
    h[i] = h[min_c];
    i = min_c;
    min_c = min_child_idx(h, i, n);
  }
  h[i] = x;
}




/*
 * delete_min heap of size n
 */
double delete_min(double h[], int n) {
  double x;
  if(n==0) return 0;  // error…
  x = h[1];
  h[1] = h[n];
  perc_down(h, 1, n-1);
  return x;
}

/**
 * rearranges array h[1..n] into a "min-heap" using
 * the "bottom-up" approach.
 *
 * Note:  capacity of array must be at least n+1
 */
void bu_build_heap(double h[], int n) {
  int i;

  for(i=n/2; i>0; i--) 
    perc_down(h, i, n);
}

/*
 * top-down build-heap
 */
void td_build_heap(double h[], int n) {
  int i;

  for(i=2; i<=n; i++) {
    perc_up(h, i);
  }
}

// utility routine
void print_arr(double a[], int n) {
  int i;

  for(i=1; i<=n; i++)
    printf("    %3.2f\n", a[i]);
}


// utility routine
void copy_arr(double src[], double dst[], int n){
  int i;

  for(i=1; i<=n; i++)
    dst[i]=src[i];
}


/* utility routine
 *   displays heap with each "layer" in tree on a separated line
 *   to see the structure of the tree more easily
 */
void print_heap(double h[], int n) {
  int i, j;
  int nper_row = 1;

  printf("\n");
  i=1;
  while(i<=n) {
    for(j=0; j<nper_row; j++) {
      if(i<=n){
        printf("  %3.2f  ", h[i]);
      }
      i++;
    }
    printf("\n");
    nper_row *= 2;
  }
}

// self-explanatory
void empty_heap(double h[], int n) {
  double x;

  printf("\n");
  while(n) {
    x = delete_min(h, n);
    printf("    %3.2f\n", x);
    n--;
  }
}

// populates array a[1..n] with random doubles
void pop_arr(double a[], int n) {
  int i;

  for(i=1; i<=n; i++) 
    a[i] = (rand()%10000)/100.0;
}

// driver program
int main(int argc, char *argv[]) {
  int n=10;

  if(argc==2)
    n = atoi(argv[1]);

  srand(time(NULL));

  double a[n+1];
  double b[n+1];


  pop_arr(a, n);
  copy_arr(a, b, n);

  printf(" ARRAY CONTENTS BEFORE BUILD-HEAP:\n");
  print_arr(a, n);


  bu_build_heap(a, n);
  printf(" ARRAY CONTENTS AFTER BU BUILD-HEAP (LAYER-BY-LAYER):\n");
  print_heap(a, n);

  td_build_heap(b, n);
  printf(" ARRAY CONTENTS AFTER TD BUILD-HEAP (LAYER-BY-LAYER):\n");
  print_heap(b, n);

  printf(" RESULTS OF EMPTYING BU HEAP VIA N DELETE_MIN OPS:\n");
  empty_heap(a, n);

  printf(" RESULTS OF EMPTYING TD HEAP VIA N DELETE_MIN OPS:\n");
  empty_heap(b, n);

  return 0;
}


