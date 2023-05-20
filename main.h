#ifndef __MAIN_H__
#define __MAIN_H__

#include <unistd.h>
#include <sys/types.h>

extern char **environ;
#define PROMPT_MSG "#cisfun$ "
#define PROMPT_LEN 9

char *_getenv(char *variable);
int _strcmp(char *s1, char *s2);
pid_t _fork(void);


#endif /* __MAIN_H__ */
