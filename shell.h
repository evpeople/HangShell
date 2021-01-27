
void parser(char *command, char *argv[], int *status); //status 两位二进制表示， 10 内置，后台 00 可执行，后台 11 内置 前台 01 可执行后台
char *isInCommand(char *command);
int isFrontCommand(char *argv[], int last);