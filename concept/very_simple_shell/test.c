#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int	main(void)
{
	char	str[] = "Bonjour les   zhoms      ";
	printf("%s\n", strtok(str, " s"));
	printf("%s\n", strtok(str, " s"));
	printf("%s\n", strtok(str, " s"));
	return (0);
}
