#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MASTER 0

int main(int argc, char **argv)
{
	int num_procs, proc_rank, global_proc_sum, rank_rcv;

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &proc_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

	rank_rcv = proc_rank;
	MPI_Reduce(&rank_rcv, &global_proc_sum,  1, MPI_INT, MPI_SUM, MASTER, MPI_COMM_WORLD);
	if (proc_rank == MASTER)
		printf("From %d using REDUCE, Rank Sum: %d\n", MASTER, global_proc_sum);

	MPI_Finalize();
	return 0;
}
