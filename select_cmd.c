#include "main.h"

/**
 * select_cmd - selects function to run for a command
 * @cmd: command to check
 * Return: pointer to function
*/
void (*select_cmd(char *cmd))(info_t *)
{
	int i = 0;
	char *copy_cmd = _strdup(cmd);
	char *token;
	command_t _commands[] = {
		{"exit", __exit},
		{"env", _env},
		{NULL, NULL}
	};

	token = _strtok(copy_cmd, " ");
	while (1 && token != NULL)
	{
		if (_commands[i].command == NULL)
			break;
		if (_strcmp(token, _commands[i].command) != 0)
		{
			i++;
			continue;
		}
		free_multiple(1, copy_cmd);
		return (_commands[i].f);
	}
	free_multiple(1, copy_cmd);
	return (_exec);
}
