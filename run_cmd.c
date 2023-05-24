#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

void run_cmd(char *command, char *shell_name)
{
	void (*exec_command)(char *, char *) = select_cmd(command);
    exec_command(command, shell_name);
}
