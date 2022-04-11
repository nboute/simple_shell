#include "main.h"

/**
 * str_replace - Replaces substring in a string with another string
 * @str: String to search in
 * @sub: Substring to look for
 * @replace: String to replace @sub with
 * Return: Newly created string
 */
char	*str_replace(char *str, char *sub, char *replace)
{
	size_t	len, len_str, len_sub, len_rep, i;
	char	*subptr, *new;

	len_str = _strlen(str);
	len_sub = _strlen(sub);
	len_rep = _strlen(replace);
	if (!len_str || !len_sub)
		return (NULL);
	subptr = _strstr(str, sub);
	len = len_str + len_rep - len_sub;
	new = (char*)malloc(len + 1);
	if (!new)
		return (NULL);
	for ( i = 0; i < subptr - str; i++)
		new[i] = str[i];
	new[i] = '\0';
	_strcat(new, replace);
	_strcat(new, subptr + len_sub);
	return (new);
}

int	main(int ac, char **av)
{
	if (ac < 4)
		return (0);
	printf("%s\n", str_replace(av[1], av[2], av[3]));
	return (0);
}
