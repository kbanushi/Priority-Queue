#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


#include "pqueue.h"
#include "macros.h"
#include "test_funcs.h"



// char *Desc= "correctness test: N inserts + N get_priorities"

int test(int n, int min_at_top) {
  int *ids;
  double *priorities;
  pqueue *q;
  _PQ *_q;
  int ret=1;

  gen_pairs(n, &ids, &priorities); 
  init_qs(ids, priorities, n, n, min_at_top, &q, &_q);

  free(ids);
  free(priorities);

  if(!peek_test(q, _q))
    ret = 0;
  // one more for good measure!
  if(!peek_test(q, _q))
    ret = 0;

  delete q;
  _pq_free(_q);
  return ret;
}





int main(int argc, char *argv[]) {
  int n = __NSMALL;
  int n2 = __N2;
  int ntrials = __NTRIALS;

  _srand(123);

  if(argc > 1)
    n = atoi(argv[1]);
  if(argc > 2)
    ntrials = atoi(argv[2]);

  /**
  set_ntrials(ntrials);

  cal_big_fudge();
  budget = calibrate_linear(n, ntrials);
  **/


  START("N inserts + 2 peek_top tests; CORRECTNESS-ONLY");

  TEST_RET_MESSAGE(test(n, 1), "CORRECTNESS-ONLY-TEST-MIN-AT-TOP", 1, 2.5); 
  TEST_RET_MESSAGE(test(n, 0), "CORRECTNESS-ONLY-TEST-MAX-AT-TOP", 1, 2.5); 

  report();

  END;
}

