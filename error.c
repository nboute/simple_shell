#include "main.h"

/**
 * print_error - Prints error message
 * @data: Pointer to general data structure
 * @command: String to complete error message
 */
void	print_error(shell_data_t *data, char *command)
{
	_putstr_fd(get_filename(_getenv("SHELL", data->envp)), STDERR_FILENO);
	_putstr_fd(": ", STDERR_FILENO);
	print_number_fd(data->nbcommands, STDERR_FILENO);
	_putstr_fd(": ", STDERR_FILENO);
	_putstr_fd(command, STDERR_FILENO);
	_putstr_fd(": Invalid command or parameter: ", STDERR_FILENO);
	_putstr_fd(data->tokens[1], STDERR_FILENO);
	_putstr_fd("\n", STDERR_FILENO);
}
