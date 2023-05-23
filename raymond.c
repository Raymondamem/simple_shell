#include "main.h"
#include <stdio.h>

int main(void) {
	int len;
	char *str = "raymond";

	len = _strlen(str);
	printf("String length is %d", len);

	return 0;
}
