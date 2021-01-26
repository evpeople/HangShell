#include "csapp.h"
void parser(char *command, char *argv[], int *status)
{
    int last = 0;
    char *tempArgv = malloc(30 * sizeof(char));
    char *beginOfArgv = tempArgv;
    while (*command != '\0')
    {
        while (*command != ' ' && *command != '\0' && *command != '\n')
        {
            *tempArgv = *command;
            tempArgv++;
            command++;
        }
        *tempArgv = '\0';
        command++;
        argv[last] = Malloc(sizeof(char) * strlen(beginOfArgv));
        strcpy(argv[last], beginOfArgv);
        last++;
        beginOfArgv = tempArgv;
    }

    if (isInCommand(argv[0]) != NULL) //默认后台执行
    {
        *status = *status | 1;
        *status = *status << 1;
    }
    else
    {
        *status = *status | 0;
        *status = *status << 1;
    }

    if (isFrontCommand(argv, last))
    {
        *status = *status | 1;
    }
}
char *isInCommand(char *command)
{
    char *InCommand = "quit jobs bg fg";
    return strstr(InCommand, command);
}
int isFrontCommand(char *argv[], int last)
{
    last -= 1;
    if (*argv[last] == '&')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}