#include <unistd.h>

/**
 * _strcmp - compares first n characters between two strings
 * @s1: First string to compare
 * @s2: Second string to compare
 * @n: Number of characters to compare
 * Return: Difference between last two different characters
 */
int	_strncmp(char *s1, char *s2, size_t n)
{
	while (*s1 && *s2 && *s1 == *s2 && --n)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}


char	*_getenv(const char *name)
{
	size_t	i, len;

	for (len = 0; name[len]; len++)
		;
	i = 0;
	while (__environ[i])
	{
		if (!_strncmp(__environ[i], (char*)name, len))
		{
			if (__environ[i][len] == '=')
				return (__environ[i] + len + 1);
		}
		i++;
	}
	return (NULL);
}
#include <stdio.h>
#include <stdlib.h>
int		main(void)
{
	char	*str;
	str = _getenv("PATH");
	if (str)
		printf("%s\n", str);
	str = getenv("PATH");
	if (str)
		printf("%s\n", str);
	return (0);
}
