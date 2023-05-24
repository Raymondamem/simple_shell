#ifndef __MAIN_H__
#define __MAIN_H__

#include <unistd.h>
#include <sys/types.h>

extern char **environ;
#define PROMPT_MSG "#cisfun$ "
#define PROMPT_LEN 9

void prompt(void);
char *_getenv(char *variable);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, const char *src);
pid_t _fork(void);
char *get_exec_path(char *program);
char **get_argv(char *line);
void free_multiple(int count, ...);
void free_array(void **array, int array_size);
void *_realloc(void *ptr, size_t size);
void *_malloc(size_t size);
void run_cmd(char *command, char *shell_name);

#endif /* __MAIN_H__ */
