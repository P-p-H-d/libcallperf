#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "libcallperf.h"

#define N 1000000000LU

int main(void)
{
  printf ("Measuring memset of size = %lu\n", N);
  libcallperf_start(NULL);
  char *p = malloc (N);
  if (!p) abort();
  for(unsigned long i = 0; i < N; i++)
    p[i] = 0;
  struct libcallperf_report_s * perf = libcallperf_stop();
  printf("Done!\nPerf result:\n");
  libcallperf_print(stdout, perf);
  printf ("Total branch miss = %f %% \n",
	  100.0 * libcallperf_get(perf, "branch-misses") /libcallperf_get(perf, "branches") );
  libcallperf_free (perf);
  return 0;
}
