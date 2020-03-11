#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define SDR_TAG 2001
#define RVR_TAG 2002
#define MASTER 0

int main(int argc, char **argv)
{
	int sum, partial;
	int pid, ierr, num_ints, num_procs, num_ints_to_recv,
	    avg_ints_per_proc, sender, num_ints_recv, start_index, 
	    end_index, num_ints_to_send;
	MPI_Status status;

	int *array, *array2;

	ierr = MPI_Init(&argc, &argv); 
	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	ierr = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

	if (pid == MASTER) {
		printf("Number of numbers to sum: ");
		scanf("%d", &num_ints);
		array = malloc(sizeof(int) * num_ints);

		avg_ints_per_proc = num_ints/num_procs;
		for (int i = 0; i < num_ints; i++) {
			array[i] = i + 1;
		}

		// Distribute - SEND - portion of vector to child processes
		for (int proc_id = 1; proc_id < num_procs; proc_id++) {
			start_index = (proc_id * avg_ints_per_proc) + 1;
			end_index = (proc_id + 1) * avg_ints_per_proc;

			if ((num_ints - end_index) < avg_ints_per_proc) {
				end_index = num_ints - 1;	
			}

			num_ints_to_send = end_index - start_index + 1;
			ierr = MPI_Send(&num_ints_to_send, 1, MPI_INT, proc_id, SDR_TAG, MPI_COMM_WORLD);
			ierr = MPI_Send(&array[start_index], num_ints_to_send, MPI_INT, proc_id, SDR_TAG, MPI_COMM_WORLD);

		}

		// Calculate Sum for MASTER process
		sum = 0;
		for (int i = 0; i < avg_ints_per_proc; i++) {
			sum += array[i];
		}
		printf("Sum from %d is %d\n", MASTER, sum);

		//Receive partial from slaves
		for (int i = 1; i < num_procs; i++) {
			ierr = MPI_Recv(&partial, 1, MPI_INT, MPI_ANY_SOURCE, RVR_TAG, MPI_COMM_WORLD, &status);
			sender = status.MPI_SOURCE;
			printf("partial from %d is %d\n", sender, partial);
			sum += partial;
		}

		printf("Grand Total: %d\n", sum);
	} else {
		//Slave thread
		array2 = malloc(sizeof(int) * num_ints);
		ierr = MPI_Recv(&num_ints_to_recv, 1, MPI_INT, MASTER, SDR_TAG, MPI_COMM_WORLD, &status);
		ierr = MPI_Recv(&array2, num_ints_recv, MPI_INT, MASTER, SDR_TAG, MPI_COMM_WORLD, &status);

		num_ints_recv = num_ints_to_recv;
		partial = 0;
		for (int i = 0; i < num_ints_recv; i++) {
			partial += array2[i];
		}

		//Send back result of partial
		ierr = MPI_Send(&partial, 1, MPI_INT, MASTER, RVR_TAG, MPI_COMM_WORLD);
		
	}
	
	ierr = MPI_Finalize();
}
