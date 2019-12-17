#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

int main(void) {
        FILE      *ptrFile = NULL;
        /* Our process ID and Session ID */
        pid_t pid=0, sid=0;
        
        /* Fork off the parent process */
        pid = fork();
        if (pid < 0) {
                exit(EXIT_FAILURE);
        }
        /* If we got a good PID, then
           we can exit the parent process. */
        if (pid > 0) {
                exit(EXIT_SUCCESS);
        }

        /* Change the file mode mask */
        umask(0);
                
        /* Open any logs here */        
                
        /* Create a new SID for the child process */
        sid = setsid();
        if (sid < 0) {
                /* Log the failure */
                exit(EXIT_FAILURE);
        }
        

        
        /* Change the current working directory */
        if ((chdir("/home/sana/workspace/daemon")) < 0) {
                /* Log the failure */
                exit(EXIT_FAILURE);
        }
        
        /* Close out the standard file descriptors */
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
        
        /* Daemon-specific initialization goes here */
       
ptrFile = fopen( "/home/sana/workspace/daemon/test2.txt", "w");

        /* The Big Loop */
        while (1) {
           /* Do some task here ... */
		//FILE      *ptrFile = fopen( "/home/sana/workspace/daemon/test.txt", "w");
           	sleep(3); /* wait 30 seconds */
		fprintf( ptrFile, "NAYEEM......\n");
		fflush(ptrFile);
	   	//fclose( ptrFile );
        }
	   	fclose( ptrFile );
   exit(EXIT_SUCCESS);
}
