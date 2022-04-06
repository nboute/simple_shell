#include "main.h"
/**
 * _strlen - calculate the lenght of a string
 * str: the string
 * Return: the lenght of the string
 */
size_t _strlen(char *str)
{
	size_t len;

	for (len = 0; str[len]; len++)
		;
	return (len);
}
/**
 * _putstr - write a string
 * @str: the string
 * Return: None
 */
void _putstr(char *str)
{
	write(1, str, _strlen(str));
}
