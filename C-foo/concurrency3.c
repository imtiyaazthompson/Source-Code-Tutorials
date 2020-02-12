#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>



void doSomeWork(char *process_name)
{
        int c;
        for(c = 0; c < 5; c++) {
                //sleep between 0 - 3 seconds
                sleep(rand() % 4);
                printf("%s step: %d\n", process_name, c);
        }
}

int main(int argc, char **argv)
{
        printf("Process: Parent --- PID: %d\n--------------------------\n", (int) getpid());

        //Fork off of the parent process, create a child process
        //pid = x for parent process, pid = 0 for child process
        //The child process contains a copy of all resources of parent?
        pid_t pid = fork();

        //Seed so that you do not follow the same sequence of rand numbers
        //Child and Parent processes sleep for different time
        srand((int) pid); 


        //This statement will execute twice
        //Once for parent and once for child
        //Child process has pid = 0
        printf("\t---fork() returned: %d\n", (int) pid);

        //Using branches to allow parent and child to perform different tasks
        if(pid < 0) {
                perror("Failed to create child process. Fork failed");
        }
        if(pid == 0) {
                //Let Child process exec some code
                printf("Process: Child --- PID: %d\n", (int) getpid());
                doSomeWork("Child");
                printf("Exiting child process, PID: %d\n", (int) getpid());
                exit(0);
        }

        //Parent process must usually wait for the child to complete
        //As to not finish before the child process rejoins the parent process
        printf("Process: Parent --- PID: %d\n", (int) getpid());
        printf("\t---Parent process is waiting...\n");
        doSomeWork("Parent");

	//Wait returns the pid of the recently terminated process
        pid_t pid_end = wait(NULL);
	printf("\t---Recently terminated process PID: %d\n", (int) pid_end);
        printf("\t---Parent process waiting complete.\n");
        printf("Parent process completed. PID: %d\n", (int) getpid());

        return 0;
}


