#include "main.h"

int main(int ac, char **av, char **envp)
{
	shell_data_t data;

	data.envp = envp;
	simple_shell(&data);
	return (0);
}
