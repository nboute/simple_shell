#include "main.h"

void	print_error(shell_data_t *data, char *command)
{
	_putstr_fd(get_filename(_getenv("SHELL", data->envp)), STDERR_FILENO);
	_putstr_fd(": ", 2);
	print_number_fd(data->nbcommands, STDERR_FILENO);
	_putstr_fd(": ", 2);
	_putstr_fd(command, 2);
	_putstr_fd(": Invalid command or parameter: ", 2);
	_putstr_fd(data->tokens[1], 2);
	_putstr_fd("\n", 2);
}
