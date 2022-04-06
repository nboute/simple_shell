#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	printf("envp:%p\nenviron:%p\n", envp, __environ);
	return (0);
}
