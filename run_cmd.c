#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

/**
 * run_cmd - runs command
 * @command: command to run
 * @shell_name: shell name
 *
 * Return: void
 */
void run_cmd(char *command, char *shell_name)
{
	void (*exec_command)(char *, char *) = select_cmd(command);

	exec_command(command, shell_name);
}
