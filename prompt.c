#include "main.h"

/**
 * prompt - Prints prompt message
*/
void prompt(void)
{
	write(STDOUT_FILENO, PROMPT_MSG, PROMPT_LEN);
}

