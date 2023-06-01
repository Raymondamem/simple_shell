#include "main.h"

/**
 * prompt - Prints prompt message
 * @shell_data: shell data information
 * Return: void
*/
void prompt(info_t *shell_data)
{
	if (shell_data->interactive == 1)
		write(STDOUT_FILENO, PROMPT_MSG, PROMPT_LEN);
}
