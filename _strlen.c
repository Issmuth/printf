#include "main.h"
/**
 * _strlen - returns the lenght of a string
 * @str: array of chars
 * Return: length of the array of chars
 */
int _strlen(const char *str)
{
	unsigned int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
