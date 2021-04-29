#include "includes.h"

int	print_error(char *error_code)
{
	if (error_code)
	{
		printf("%sError\n", "\x1B[31m");
		printf("%s%s\n", error_code, "\x1B[0m");
	}
	else
		printf("exit without error\n");
	exit(0);
	//return (0);
}
