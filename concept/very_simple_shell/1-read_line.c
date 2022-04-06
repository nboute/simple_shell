#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*buf = NULL;
	size_t	i, n = 0;

	do
	{
		if (buf)
		{
			printf("%s\n", buf);
			free(buf);
			buf = NULL;
		}
		printf("$ ");
	} while (getline(&buf, &n, stdin) != -1);
	return (0);
}
