#include "main.h"
#include <stdlib.h>

/**
 * __exit - exit from shell
 * @shell_data: shell data
 * Return: void
*/
void __exit(info_t *shell_data)
{
	free_multiple(1, shell_data->line);
	exit(EXIT_SUCCESS);
}
