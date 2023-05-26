#ifndef __MAIN_H__
#define __MAIN_H__

#include <unistd.h>
#include <sys/types.h>

extern char **environ;

#define PROMPT_MSG "$ "
#define PROMPT_LEN 2

#define UNUSED(x) (void)(x)
#define PATH_MAX 1024

/**
 * struct info - more information
 * @line: commands typed
 * @interactive: shell mode
 * @shell_name: name of the shell
*/
typedef struct info
{
	char *line;
	int interactive;
	char shell_name[5];
} info_t;

/**
 * struct cmd - command structure
 * @command: format specifier
 * @f: command function
*/
typedef struct cmd
{
	char *command;
	void (*f)(info_t *);
} command_t;

void prompt(void);
void (*select_cmd(char *cmd))(info_t *);
char *_getenv(char *variable);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strlen(const char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, const char *src);
char *_strtok(char *str, const char *delim);
pid_t _fork(void);
char *get_exec_path(char *program);
char **get_argv(char *line);
void free_multiple(int count, ...);
void free_array(void **array, int array_size);
void *_realloc(void *ptr, size_t size);
void *_malloc(size_t size);
char *_strdup(const char *s);
void run_cmd(info_t *);
void _exec(info_t *);
void __exit(info_t *);
void _env(info_t *);

#endif /* __MAIN_H__ */
