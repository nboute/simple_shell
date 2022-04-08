#include "main.h"

/**
 * _memalloc - Allocates memory and sets it to 0
 * @size: Size of memory to allocate
 * Return: Pointer to newly allocated block
 */
void	*_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr)
		_bzero(ptr, size);
	return (ptr);
}

/**
 * _strcat - concatenates two strings
 * @dest: string to append to
 * @src: string to append to dest
 * Return: dest
 */
char	*_strcat(char *dest, char *src)
{
	char	*str;

	str = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (str);
}

/**
 * _strncmp - compares first n characters between two strings
 * @s1: First string to compare
 * @s2: Second string to compare
 * @n: Number of characters to compare
 * Return: Difference between last two different characters
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	while (*s1 && *s2 && *s1 == *s2 && --n)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
