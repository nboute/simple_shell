#include "main.h"

/**
 * _strcpy - copy string's content into another
 * @dest: string to copy into
 * @src: string to copy from
 * Return: returns string where content was pasted
 */
char	*_strcpy(char *dest, const char *src)
{
	int	i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - Creates a duplicate of a given string
 * @str: String to duplicate
 * Return: Duplicate of @str
 */

char	*_strdup(const char *str)
{
	size_t	len;
	char	*dup;

	if (!str)
		return (NULL);
	len = _strlen(str);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	return (_strcpy(dup, str));
}

/**
 * _putchar_fd - writes the character c to fd
 * @c: The character to print
 * @fd: file descriptor to print char to
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

/**
 * print_number_fd - prints number to fd
 *
 * @n: number to print
 * @fd: fd to print to
 */

void	print_number_fd(int n, int fd)
{
	if (n < 0)
	{
		_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			_putchar_fd('2', fd);
			print_number_fd(147483648, fd);
		}
		else
			print_number_fd(-n, fd);
	}
	else if (n > 9)
	{
		print_number_fd(n / 10, fd);
		_putchar_fd(n % 10 + '0', fd);
	}
	else
		_putchar_fd(n % 10 + '0', fd);
}

/**
 * _atoi - converts string into an integer
 * @s: string to convert
 * Return: integer format of string
 */
int	_atoi(char *s)
{
	int	sign;
	int	nb;

	nb = 0;
	sign = 1;
	while (*s && (*s < '0' || *s > '9'))
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		if ((nb == -214748364 && *s == '9') || nb < -2141748364)
			break;
		if ((nb == 214748364 && *s >= '8') || nb > 2141748364)
			break;
		if (sign == 1)
			nb = nb * 10 + (*s - '0');
		else if (sign == -1)
			nb = nb * 10 - (*s - '0');
		s++;
	}
	return (nb);
}
