#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//Attempting to run the sum, but now on many threads
//There should ideally be only one pthread_join() call
//Since we want our multiple threads to run concurrently
//Then join the main thread right at the end

struct sum_runner_struct {
	long long n;
	long long answer;
};

//Thread function to generate sum of 0 -> N
void* sum_runner(void *arg)
{
	//Type cast void pointer to a struct pointer
	struct sum_runner_struct *arg_struct = (struct sum_runner_struct*) arg;

	long long i;
	for(i = 0; i <= arg_struct->n; i++) {
		sum += i;
	}

	//Since threads execute in the same address space they wil have access 
	//to the same global data

	//This thread need to terminate
	//This exit status gets passed back whatever was the argument in pthread_join(tid,xxx)
	//Could Dynamically allocate space and pass the answer back
	//Never want to return a pointer to a local variable that is on the stack
	//Because upon exiting the function, all local variables gets popped off the stack
	//The memory is deallocated and the pointer now points to nothing
	//Instead, have the function also accept as a param a piece of memory to write
	//the answer into
	pthread_exit(0);
	
}

int main(int argc, int **argv)
{
	//Main thread starts here
	if(argc < 2) {
		printf("Usage: %s <num1> <num2> <num3> . . . <num n>\n", argv[0]);
		exit(-1);
	}

	int number_of_threads = argc - 1;

	//Sum some numbers on a background thread
		
	//Thread ID:
	//Require a unique thread ID for each thread that is spawned
	//Init attr inside for loop
	pthread_t tids[number_of_threads];
	int i;
	for(int i = 0; i < number_of_threads; i++) {
		long long n = atoll(argv[i+1]);
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_create(&tids[i], &attr, &sum_runner, &n);		
	}

	//Wait until all threads complete before exiting
	for(int i = 0; i < number_of_threads; i++) {
		pthread_join(tids[0], NULL);
	}
	printf("Sum is : %lld\n", sum);

	return 0;
}
