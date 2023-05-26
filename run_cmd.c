#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

/**
 * run_cmd - runs command
 * @shell_data: shell data
 *
 * Return: void
 */
void run_cmd(info_t *shell_data)
{
	void (*exec_command)(info_t *) = select_cmd(shell_data->line);

	exec_command(shell_data);
}
