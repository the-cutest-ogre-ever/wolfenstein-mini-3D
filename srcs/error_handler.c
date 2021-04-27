#include "includes.h"

int print_error(char *error_code)
{
	printf("%sError\n", "\x1B[31m");
	printf("%s%s\n", error_code, "\x1B[0m");
	return (0);
}
