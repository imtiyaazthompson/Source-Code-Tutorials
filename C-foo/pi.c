#include <stdio.h>
#include "omp.h"

#define NUM_THREADS 2

 /**
  * Fork-Join model
  * Fork a number of threads from a single process line at a juncture
  * where you think parallelism might help
  * Master thread continues out of that block of parallel threads ID=0
  * Collection of threads <==> Team of threads
  * When team of threads complete their parallel exec, they join back together
  * into the master
  * Threads can be nested, a single thread in the team can fork into a sub-team
  * of threads
  **/

int main()
{
	double A[1000];
	double sum[NUM_THREADS];
	int i;
	double pi;
	omp_set_num_threads(NUM_THREADS);
	//This construct creates multiple threads
	//Will fork a number of threads, in this case 4
	//Data alloc'd here is located on the heap
	double start = omp_get_wtime();
	#pragma omp parallel	
	{
		//Each thread will run the code in this structured block
		//Data alloc'd here is located on the threads individual stack
		//Each thread can see A[], but each thread will have its own copy of 
		//ID
		int ID = omp_get_thread_num();
		sum[ID] = 0.0;
		static long num_steps = 100000; //preserve value out of scope
		double step;
		int i;
		double x, pi, sum[NUM_THREADS];
		step = 1.0/(double) num_steps;
		for (i = 0; i < num_steps; i++) {
			x = (i + 0.5)*step;
			sum[ID] = sum[ID] + 4.0/(1.0 + x*x);
		}
	}
	double end = omp_get_wtime();
	pi = 0.0;
	for (i = 0;)

	printf("all done aftr %.2fs\n", end - start);

	return 0; 
}
