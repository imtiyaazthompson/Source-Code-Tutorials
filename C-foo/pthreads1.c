#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//When compiling:
//$gcc prog.c -pthreads -o prog

//Difference between child processes and threads:
//Processes that create child processes - they all run in seperate memory spaces
//Where as threads of execution of a process - they all run in a shared memory space
//Think of forking a process as just a creation of a new process from the already executing 
//parent process
//Parent and child process posses the same code segment but execute independently of one another

//Threads require less overhead than forking
//Pthread requires a function pointer as an argument that returns a void pointer and has void* param
//The function pointer is require as it is a type of generic way to say - run this function on a back//ground thread
//Where you start executing the thread from

long long sum = 0;

//Thread function to generate sum of 0 -> N
void* sum_runner(void *arg)
{
	//Type cast void pointer to long long pointer
	long long *p_n = (long long *) arg;
	long long n = *p_n; //Dereferenc ptr to get value @address of ptr

	long long i;
	for(i = 0; i <= n; i++) {
		sum += i;
	}

	//Since threads execute in the same address space they wil have access 
	//to the same global data

	//This thread need to terminate
	//This exit status gets passed back whatever was the argument in pthread_join(tid,xxx)
	pthread_exit(0);
	
}

int main(int argc, int **argv)
{
	//Main thread starts here
	if(argc < 2) {
		printf("Usage: %s <num>\n", argv[0]);
		exit(-1);
	}

	//Sum some numbers on a background thread
	long long limit = atoll(argv[1]);
	
	//Thread ID:
	//Track which thread you are working on
	pthread_t tid;

	//Attributes: How is the thread going to function
	//Init attr
	pthread_attr_t attr; 
	pthread_attr_init(&attr);

	//A new thread starts here
	//No brackets for address of function - function pointer
	//Since we do not want to run the function and have its return as a 
	//param to pthread
	//Last param is the args for your function
	pthread_create(&tid, &attr, &sum_runner, &limit);
	
	//Wait until thread completed before exiting
	pthread_join(tid, NULL);
	printf("Sum is : %lld\n", sum);

	return 0;
}
