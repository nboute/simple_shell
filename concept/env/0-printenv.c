#include <stdio.h>
#include <unistd.h>
int	main(void)
{
	int	i;

	i = 0;
	while (__environ[i])
		printf("%s\n", __environ[i++]);
	return (0);
}
