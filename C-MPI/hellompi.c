#include <stdio.h>
#include <string.h>
#include <mpi.h>

#define MAX_STR 100
#define MASTER 0
#define R_TAG 80

int main(int argc, char **argv)
{
	char greeting[MAX_STR];
	int num_procs;
	int proc_rank;

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
	MPI_Comm_rank(MPI_COMM_WORLD, &proc_rank);

	if (proc_rank == MASTER) {
		printf("Greetings from proc %d of %d\n", proc_rank, num_procs);
		// Master process will receive messages sent from other slave processes
		// Use MPI_ANY_SOURCE to receive messages from a processes in any order
		// and not necessarily sequentially, Similarly with MPI_ANY_TAG
		// If the receiving process receives messages from a process that
		// uses different tags (So receiving process can interpret messages 
		// based on varying tags), use MPI_ANY_TAG
		// Only receivers can use wild card args
		//If the receiver does not know the TAG or SOURCE, the status can be used to find it
		for (int i = 1; i < num_procs; i++) {
			MPI_Recv(greeting, MAX_STR, MPI_CHAR, /*i*/MPI_ANY_SOURCE, R_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("%s", greeting);
		}
	} else {
		// Each Slave process will Send Messages back to the MASTER process
		sprintf(greeting, "Greetings from proc %d of %d\n", proc_rank, num_procs);
		MPI_Send(greeting, strlen(greeting) + 1, MPI_CHAR, MASTER, R_TAG, MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;
}
