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
int main(void)
{
	pid_t id;
	ssize_t read;
	size_t len = 0;
	char *argv[2] = { NULL, NULL };


	prompt();
	while ((read = getline(&argv[0], &len, stdin)) != -1)
	{
		argv[0][read - 1] = '\0';
		id = _fork();
		if (id == 0)
		{

			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error");
				_exit(EXIT_FAILURE);
			}
		}
	}

	return (0);
}
