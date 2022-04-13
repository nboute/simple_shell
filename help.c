#include "main.h"
/**
 *_help - writes the help built-in
 *@addr: Pointer to data structure
 *Return: None
 */
int _help(void *addr)
{
	shell_data_t	*data;

	data = (shell_data_t *)addr;
	if (!data->tokens[1])
	{
		_putstr("Try 'help exit' or 'help setenv' or 'help unsetenv' or");
		_putstr("'help cd' or 'help env'\n");
	}
	else if (_strcmp(data->tokens[1], "exit") == 0)
	{
		_putstr("exit (nb)\nExit the shell.\n\nThe number permits to have the");
		_putstr("return value of the exit.\n");
	}
	else if (_strcmp(data->tokens[1], "setenv") == 0)
	{
		_putstr("setenv: change or add an environment variable\nIt's possible");
		_putstr("to change a value of a variable\nusage: setenv NAME value\n");
	}
	else if (_strcmp(data->tokens[1], "unsetenv") == 0)
	{
		_putstr("unsetenv: delete the variable name from the environment\n");
		_putstr("usage: unsetenv NAME\n");
	}
	else if (_strcmp(data->tokens[1], "cd") == 0)
	{
		_putstr("cd: change the shell working directory\n usage: cd name of");
		_putstr("the next directory\n");
	}
	else if (_strcmp(data->tokens[1], "env") == 0)
		_putstr("env: print the environment variable\n");
	else
		_putstr("command invalid\n");
	return (0);
}
