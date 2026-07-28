#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("Child running...\n");
        sleep(2);
        printf("Child finished.\n");
    }
    else
    {
        wait(NULL);
        printf("Parent continues.\n");
    }
    return 0;
}