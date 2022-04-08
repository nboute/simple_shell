#include "main.h"
/**
 * _strcmp - compares two string
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: Difference between last two different characters
 */
int	_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * free_tab - Frees double entry array
 * @tab: Address of array to free
 */
void free_tab(char ***tab)
{
	int i = 0;

	if (tab && *tab)
	{
		while ((*tab)[i])
			free((*tab)[i++]);
		free((*tab));
		*tab = NULL;
	}
}

/**
 * _memdel - Frees pointer and sets its value to NULL
 * @ptr: Address of pointer to free
 */
void	_memdel(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

/**
 * _bzero - set n bytes from a buffer to 0
 * @dest: destination buffer
 * @n: number of bytes to set
 * Return: Destination buffer @dest
 */
void	*_bzero(void *dest, unsigned int n)
{
	long	*lptr;
	char	*ptr;
	unsigned int	size;

	lptr = (long *)dest;
	size = sizeof(long);
	while (n >= size)
	{
		*lptr++ = 0;
		n -= size;
	}
	ptr = (char *)lptr;
	while (n--)
		*ptr++ = 0;
	return (dest);
}
