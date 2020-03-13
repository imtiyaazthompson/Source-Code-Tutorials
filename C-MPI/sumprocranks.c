#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MASTER 0

int main(int argc, char **argv)
{
	int proc_rank, num_procs, global_proc_sum, rank_rcv;
	MPI_Status status;

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &proc_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

	if (proc_rank == MASTER) {
		for (int i = 1; i < num_procs; i++) {
			MPI_Recv(&rank_rcv, 1, MPI_INT, MPI_ANY_SOURCE, 2, MPI_COMM_WORLD, &status);
			printf("Received rank: %d from Proc %d\n", rank_rcv, status.MPI_SOURCE);
			global_proc_sum += rank_rcv;
		}

		printf("Sum of all ranks: %d\n", global_proc_sum);
	} else {
		MPI_Send(&proc_rank, 1, MPI_INT, MASTER, 2, MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;
}
