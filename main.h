#ifndef __MAIN_H__
#define __MAIN_H__

#include <unistd.h>
#include <sys/types.h>

extern char **environ;

#define PROMPT_MSG "($) "
#define PROMPT_LEN 4

#define UNUSED(x) (void)(x)
#define PATH_MAX 1024

/**
 * struct cmd - command structure
 * @command: format specifier
 * @f: command function
*/
typedef struct cmd
{
	char *command;
	void (*f)(char *c, char *s);
} command_t;

void prompt(void);
void (*select_cmd(char *cmd))(char *c, char *s);
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
void run_cmd(char *command, char *shell_name);
char *_strdup(const char *s);
void _exec(char *command, char *shell_name);
void __exit(char *command, char *shell_name);
void _env(char *command, char *shell_name);

#endif /* __MAIN_H__ */
