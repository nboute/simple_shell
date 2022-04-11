#include "main.h"

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	char **tab = _strsplit(av[1], ";");
	while (*tab)
	{
		printf("[%s]\n", *tab);
		tab++;
	}
	return (0);
}
