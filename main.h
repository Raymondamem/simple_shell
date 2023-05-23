#ifndef __MAIN_H__
#define __MAIN_H__

#include <unistd.h>
#include <sys/types.h>

extern char **environ;
#define PROMPT_MSG "#cisfun$ "
#define PROMPT_LEN 9

char *_getenv(char *variable);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
pid_t _fork(void);


#endif /* __MAIN_H__ */
