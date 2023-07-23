#include "main.h"
/**
 * _atoi - converts strings into integers
 * @str: the string to manipulate
 * Return: interger of the string
 */
int _atoi(char *str)
{
	int x = 0, i = 0;
	unsigned int y = 0;

	while (!(str[i] <= '9' && str[i] >= '0') && str[i] != '\0')
	{
		if (str[i] == '-')
			x *= -1;
		i++;
	}
	while (str[i] <= '9' && (str[i] >= '0' && str[i] != '\0'))
	{
		y = (y * 10) + (str[i] - '0');
		i++;
	}
	y *= x;
	return (y);
}
