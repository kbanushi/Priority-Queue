#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "pqueue.h"
#include "macros.h"
#include "test_funcs.h"


int test(int n, int min_at_top) {
  int *ids;
  double *priorities;
  pqueue *q;
  double p;
  int id, i;

  gen_pairs(n, &ids, &priorities); 

  init_qs_rt(ids, priorities, n, n, min_at_top, &q);

  for(id=0; id<n; id++) {
    q->get_priority( id, p); 
  }

  free(ids);
  free(priorities);

  delete q;

  return 1;
}





int main(int argc, char *argv[]) {
  int n = ___N;
  int n2 = __N2;
  int ntrials = __NTRIALS;
  clock_t budget;

  _srand(123);

  if(argc > 1)
    n = atoi(argv[1]);
  if(argc > 2)
    ntrials = atoi(argv[2]);

  set_ntrials(ntrials);
  // cal_big_fudge();
  // budget = calibrate_linear(n, ntrials);



  START("RUNTIME test of N inserts + N get_priority ops");

  TIME2(test(n, 1), test(n2, 1), "RUNTIME-TEST: insert+get_priority", 1, 2.5, 10.0); 

  report();

  END;
}

