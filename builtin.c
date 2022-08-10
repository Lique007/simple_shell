#include "simple_shell.h"

int exit_function(char **args, char *line)
{
	int number;

	number = 0;
	if (args[1] != NULL)
		number = _atoi(args[1]);
	if (number == -1)
	{
		return (-1);
	}
	else
	{
		free_function(1, line);
		free_function(2, args);
		exit(number);
	}
}

int print_env(void)
{
	int x;

	for (x = 0; environ[x] != NULL; x++)
	{
		write(STDOUT_FILENO, environ[x], strlen(environ[x]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

void sigign(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n($) ", 5);
}
