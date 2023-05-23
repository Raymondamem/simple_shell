#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * prompt - Prints prompt message
*/
void prompt(void)
{
	write(STDOUT_FILENO, PROMPT_MSG, PROMPT_LEN);
}

/**
 * main - Entry point for shell
 * Return: 0 on success, -1 on failure
*/
int main(__attribute__((unused)) int ac, char **av)
{
	pid_t id;
	ssize_t read;
	size_t len = 0;
	char *line = NULL;
	char **argv = NULL;
	char *full_path = NULL;
	int i;

	prompt();
	while ((read = getline(&line, &len, stdin)) != -1)
	{
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		
		argv = get_argv(line);
		full_path = get_exec_path(argv[0]);
		if (full_path == NULL)
		{
			perror("File not found");
			_exit(EXIT_FAILURE);
		}
		id = _fork();
		if (id == 0)
		{
			if (execve(full_path, argv, NULL) == -1)
			{
				perror(av[0]);
				_exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv);
		prompt();
	}
	if (line != NULL)
		free(line);
	if (full_path != NULL)
		free(full_path);
	return (0);
}
