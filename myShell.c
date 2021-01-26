#include "csapp.h"
#include "shell.h"

int a;
volatile int counter = 0;
void handler(int sig)
{

    Sio_puts("\ngood bye\n");
    exit(0);
}

int main(int argc, char *argv[], char *envp[])
{
    int i = 0;
    int pid;
    char cmd[30];
    char *argvOfMyShell[50];
    printf("Enter your command\n>");
    Signal(SIGINT, handler);

    while (1)
    {
        Fgets(cmd, 90, stdin);
        parser(cmd, argvOfMyShell, &i);
        if ((pid = Fork()) == 0)
        {
            Execve(argvOfMyShell[0], argvOfMyShell, environ);
        }
        int status;
        //sleep(5);
        (Waitpid(pid, &status, 0));

        printf(">");
    }

    printf("counter=%d", counter);
    printf("counter=%d", counter);

    printf("counter=%d", counter);

    exit(0);
}