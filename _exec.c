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
	char **env_vars = _malloc((*envp_size) * sizeof(char *));
	char *lc_collate = _getenv("LC_COLLATE");
	char *lc_all = _getenv("LC_ALL");
	char *lang = _getenv("LANG");
	int i = 0;

	if (lc_collate != NULL)
	{
		env_vars[i] = _malloc(_strlen("LC_COLLATE=") + _strlen(lc_collate) + 1);
		_strcpy(env_vars[i], "LC_COLLATE=");
		_strcat(env_vars[i], lc_collate);
		i++;
	}
	else
		env_vars[i] = NULL;
	if (lc_all != NULL)
	{
		env_vars[i] = _malloc(_strlen("LC_ALL=") + _strlen(lc_all) + 1);
		_strcpy(env_vars[i], "LC_ALL=");
		_strcat(env_vars[i], lc_all);
		i++;
	}
	else
		env_vars[i] = NULL;
	if (lang != NULL)
	{
		env_vars[i] = _malloc(_strlen("LANG=") + _strlen(lang) + 1);
		_strcpy(env_vars[i], "LANG=");
		_strcat(env_vars[i], lang);
		i++;
	}
	else
		env_vars[i] = NULL;
	env_vars[i] = NULL;

	return (env_vars);
}

/**
 * _exec - execute a program
 * @shell_data: shell data
 * Return: void
*/
void _exec(info_t *shell_data)
{
	char *full_path = NULL;
	char **argv = NULL, **envp = NULL;
	pid_t id;
	int envp_size = 4, wstatus;

	envp = get_lang_env(&envp_size);
	argv = get_argv(shell_data->line);
	if (argv[0] == NULL)
		exit(EXIT_SUCCESS);
	else if (argv[0][0] != '/' && argv[0][0] != '.')
		full_path = get_exec_path(argv[0]);
	else
		full_path = _strdup(argv[0]);
	if (full_path == NULL)
	{
		perror(shell_data->shell_name);
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
				perror(shell_data->shell_name);
				exit(EXIT_FAILURE);
			}
		}
		wait(&wstatus);
		free_array((void **)envp, envp_size);
		free_array((void **)argv, sizeof(argv) / sizeof(char));
		free_multiple(2, full_path, shell_data->line);
		if (shell_data->interactive == 0)
		{
			if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) != 0)
				exit(2);
		}
	}
}
