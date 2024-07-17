#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>

#include "pqueue.h"  // C++

#include "macros.h"  // macros
#include "test_funcs.h"  // slow c imp




std::string _desc = "basic correctness test: n insertions + n deletes";
const char *Desc= _desc.c_str();


/*
 *
 *   just does trivial tests of pq_capacity and pq_size
 *
 */
int test(int n, int min_at_top) {
  int *ids;
  double *priorities;
  // PQ *q;
  pqueue *q;
  _PQ *_q;
  int ret=1;
  int id;
  double prio;

  gen_pairs(n, &ids, &priorities); 
  init_qs(ids, priorities, n, n, min_at_top, &q, &_q);

  if(q->capacity() != n){
    printf("  pq->capacity wrong!\n");
    ret = 0;
  }
  if(q->size() != n){
    printf("  pq_size wrong!\n");
    ret = 0;
  }

  q->delete_top(id, prio);

  if(q->size() != n-1){
    printf("  pq_size wrong!\n");
    ret = 0;
  }

  free(ids);
  free(priorities);

  // pq_free(q);
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


  START("TRIVIAL pq_capacity AND pq_size TESTS");

  TEST_RET_MESSAGE(test(n, 1), "CORRECTNESS-ONLY-TEST-capacity+size", 1, 5.0); 
  report();

  END;
}

