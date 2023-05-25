#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

/**
 * get_lang_env - get the language environment
 * @envp_size: size of the environment
 * Return: pointer to the language environment
*/
char **get_lang_env(int *envp_size)
{
	char **envp = NULL;
	char *lang = _getenv("LANG");

	envp = _malloc((*envp_size) * sizeof(char *));
	envp[0] = _malloc(5 + _strlen(lang) + 1);
	_strcat(envp[0], "LANG=");
	_strcat(envp[0], lang);
	return (envp);
}

/**
 * _exec - execute a program
 * @command: command to execute
 * @shell_name: name of the shell
 * Return: void
*/
void _exec(char *command, char *shell_name)
{
	char *full_path = NULL;
	char **argv = NULL, **envp = NULL;
	pid_t id;
	int envp_size = 3;

	envp = get_lang_env(&envp_size);
	argv = get_argv(command);
	if (argv[0] == NULL)
		exit(EXIT_SUCCESS);
	else if (argv[0][0] != '/' && argv[0][0] != '.')
		full_path = get_exec_path(argv[0]);
	else
		full_path = _strdup(argv[0]);
	if (full_path == NULL)
	{
		perror(shell_name);
		free_array((void **)argv, sizeof(argv) / sizeof(char));
		free_array((void **)envp, envp_size);
	}
	else
	{
		id = _fork();
		if (id == 0)
		{
			if (execve(full_path, argv, envp) == -1)
			{
				perror(shell_name);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
		free_array((void **)envp, envp_size);
		free_array((void **)argv, sizeof(argv) / sizeof(char));
		free_multiple(1, full_path);
	}
}
