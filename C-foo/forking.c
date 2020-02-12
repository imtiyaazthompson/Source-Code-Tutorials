#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	printf("Process: Parent --- PID: %d\n--------------------------\n", (int) getpid());

	//Fork off of the parent process, create a child process
	//pid = x for parent process, pid = 0 for child process
	//The child process contains a copy of all resources of parent?
	pid_t pid = fork();

	//This statement will execute twice
	//Once for parent and once for child
	//Child process has pid = 0
	printf("\t---fork() returned: %d\n", (int) pid);

	//Using branches to allow parent and child to perform different tasks
	if(pid < 0) {
		perror("Failed to create child process. Fork failed");
	} else if(pid == 0) {
		printf("Process: Child --- PID: %d\n", (int) getpid());
	} else {
		printf("Process: Parent --- PID: %d\n", (int) getpid());
	}

	//This statement will execute for both parent and child process
	printf("PID: %d - completed\n", (int) getpid());

	return 0;
}
