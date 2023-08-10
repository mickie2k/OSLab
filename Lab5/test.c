#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{ // 1ab5q2.c
    pid_t cpid;
    pid_t gcpid;
    // / * fork another process */
    cpid = fork();
    // if (cpid < 0)
    // { // error occurred
    //     fprintf(stderr, "Fork Failed");
    //     exit(-1);
    // }  else {
    if (cpid == 0)
    {

        gcpid = fork();
        if (gcpid == 0)
        { // grandchild
            printf("can you see this3?\n");
            exit(0);
        }
        execlp("type", "type cd", NULL);
        exit(0);
        printf("can you see this2?\n");
        
    }

 
        // parent process will wait for the child to complete */
        
        wait(NULL);
        printf("can you see this1?\n");
        printf("received Child Complete\n");
        exit(0);
        
    
    return 0;
}