#include "main.h"

/**
 * select_cmd - selects function to run for a command
 * @cmd: command to check
 * Return: pointer to function
*/
void (*select_cmd(char *cmd))(info_t *)
{
	int i = 0;
	command_t _commands[] = {
		{"exit", __exit},
		{"env", _env},
		{NULL, NULL}
	};

	while (1)
	{
		if (_commands[i].command == NULL)
		{
			break;
		}
		if (_strcmp(cmd, _commands[i].command) != 0)
		{
			i++;
			continue;
		}
		return (_commands[i].f);
	}
	return (_exec);
}
