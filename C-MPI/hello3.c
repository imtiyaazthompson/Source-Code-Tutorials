#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char **argv)
{
	int num1,num2,ierr,pid;
	MPI_Status status;

	if (argc == 3) {
		num1 = atoi(argv[1]);
		num2 = atoi(argv[2]);
	} else {
		exit(0);
	}

	/*
	 * This is where the different processes are forked
	 * Every variable declared here is made private to all
	 * the processes forked	
	 */	

	ierr = MPI_Init(&argc, &argv);
	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &pid);

	if (pid == 0) {
		printf("From proc %i, we add %d and %d = %d\n", pid, num1, num2, num1+num2);
	} else if (pid == 1) {
		printf("From proc %i, we subtract %d and %d = %d\n", pid, num1, num2, num1-num2);
	} else if (pid == 2) {
		printf("From proc %i, we multiply %d and %d = %d\n", pid, num1, num2, num1*num2);
	} else {
		printf("From proc %i, we divide %d and %d = %d\n", pid, num1, num2, num1/num2);
	}

	ierr = MPI_Finalize();
	return 0;
}
