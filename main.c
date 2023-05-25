#include "main.h"
#include <stdio.h>
#include <signal.h>



/**
 * main - Entry point for shell
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success, -1 on failure
*/
int main(__attribute__((unused)) int ac, char **av)
{
	ssize_t read;
	size_t len = 0;
	char *line = NULL;

	if (isatty(STDIN_FILENO))
	{
		prompt();
		while ((read = getline(&line, &len, stdin)) != -1)
		{
			if (line[read - 1] == '\n')
				line[read - 1] = '\0';

			run_cmd(line, av[0]);
			prompt();
		}
	}
	else
	{
		while ((read = getline(&line, &len, stdin)) != -1)
		{
			if (line[read - 1] == '\n')
				line[read - 1] = '\0';

			run_cmd(line,  av[0]);
		}
	}
	free_multiple(1, line);
	return (0);
}
