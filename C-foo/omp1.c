#include <stdio.h>
#include "omp.h"

/**
 * $export OMP_NUM_THREADS=4
 **/

 /**
  * Decomposes processes into threads by fragmenting the stack for each process
  * Each thread has its own chunk of the stack
  * Each thread maintains its own program counter, stack pointer and registers
  * But the threads share the text, data and heap regions
  * Block of threads that share a process, threads have a shared context of the process
  * You can context switch between threads very cheaply
  * 
  * One Process - Many Threads
  * Threads interact through R/W to a shared address space
  * Scheduler decides when to run which threads
  * Threads have their own stack, Threads share the heap of the process
  * Could have multiple threads per processor core
  * 
  * Think of every conceivable way to interleave those threads
  **/

int main()
{
	//Give me a bunch of threads, unless stated, give me the default number
	#pragma omp parallel 
	{	
		//Runtime lib routine to set ID
		//Returns an identifier for each thread [0 - threads-1]
		int ID = omp_get_thread_num();
		printf("Hello(%d) ", ID);
		printf("World(%d)\n", ID);
	}//close structured block

	 /**
          * In the above case, since threads are interleaved Hello(0)
          * might be followed by Hello(3) since Hello is printed first 
	  * from thread 3 before any other threads (1),(2)
	  **/

	 /**
   	  * Race condition: threads performing ops on a shared resource
	  * where another resource may try and access it and results may
    	  * vary
	  * Program's outcome changes as threads are scheduled differntly
	  **/

	 /**
          * To control race conditions -> sychcronization to protect
          * data conflicts
          **/		 
	return 0;
}
