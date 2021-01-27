#include "csapp.h"
#include "shell.h"
#define BACK 0
#define FRONT 1

int pid[1000];
volatile int counter = 0;
void handler(int sig)
{

    Sio_puts("\ngood bye\n");
    exit(0);
}
void callExe(const char *filename, char *const argv[], char *const envp[], int backOfFront);
void callCommand(const char *filename, char *const argv[], char *const envp[], int backOfFront);

int main(int argc, char *argv[], char *envp[])
{
    int i = 0;
    //int pid;
    char cmd[30];
    char *argvOfMyShell[50];
    printf("Enter your command\n>");
    Signal(SIGINT, handler);

    while (1)
    {
        Fgets(cmd, 90, stdin);
        parser(cmd, argvOfMyShell, &i);
        switch (i)
        {
        case 0:
            callExe(argvOfMyShell[0], argvOfMyShell, environ, i);
            break;
        case 1:
            callExe(argvOfMyShell[0], argvOfMyShell, environ, i);
            break;
        case 2:
            callCommand(argvOfMyShell[0], argvOfMyShell, environ, i);
            break;
        case 3:
            callCommand(argvOfMyShell[0], argvOfMyShell, environ, i);
            break;
        default:
            printf(":SADAS");
            break;
        }
        // if ((pid = Fork()) == 0)
        // {
        // Execve(argvOfMyShell[0], argvOfMyShell, environ);
        // }
        // int status;
        // //sleep(5);
        // (Waitpid(pid, &status, 0));

        printf(">");
        memset(argvOfMyShell[1], 60, sizeof(char));
        i = 0;
    }

    printf("counter=%d", counter);
    printf("counter=%d", counter);

    printf("counter=%d", counter);

    exit(0);
}
void callExe(const char *filename, char *const argv[], char *const envp[], int backOfFront)
{
    int pid;
    printf("%d", (backOfFront & 1) == BACK);
    //Sleep(1);
    if ((backOfFront & 1) == BACK)
    {
        if ((pid = Fork()) == 0)
        {
            Execve(filename, argv, envp);
        }
    }
    else
    {
        if ((pid = Fork()) == 0)
        {
            Execve(filename, argv, envp);
        }
        int status;
        //sleep(5);
        (Waitpid(pid, &status, 0));
    }
}
void callCommand(const char *filename, char *const argv[], char *const envp[], int backOfFront)
{
}