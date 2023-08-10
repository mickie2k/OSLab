#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    pid_t cpid;
    char userChoice = 'z';

    while (userChoice != 'q')
    {
        // print menu
        printf("a: ls\n");
        printf("b: ps\n");
        printf("c: who\n");
        printf("q for quit\n");
        scanf(" %c", &userChoice);
        // your code 1
        cpid = fork();
        // child begin
        if (cpid == 0)
        {
            switch (userChoice)
            {
            case 'a':
                execlp("ls", "ls", NULL);
                break;
            case 'b':
                execlp("ps", "ps", NULL);
                break;
            case 'c':
                execlp("whoami", "whoami", NULL);
                break;

            default:
                exit(0);
                break;
            }
        }
        wait(NULL);

        // your code 2

    } // while

    printf("parent terminated\n");
    exit(0);
    return 0;
}
