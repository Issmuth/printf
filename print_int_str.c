#include "main.h"
/**
 * print_int_str - returns a string of chars which are int
 * @num: actual integer
 * @buffer: array of chars
 * Return: void
 */
void print_int_str(int num, char *buffer)
{
	int i = 0, j = 0, is_negative = 0, left = 0 /*right = i - 1*/;
	char *temp;

	temp = malloc(_strlen(buffer) * sizeof(char));
	if (temp == NULL)
	{
		printf("Memory allocation failed");
		return;
	}
	if (num == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return;
	}
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	while (num != 0)
	{
		buffer[i++] = '0' + num % 10;
		num /= 10;
	}
	if (is_negative)
	{
		buffer[i++] = '-';
	}
	buffer[i] = '\0';
	for (left = (_strlen(buffer) - 1); left >= 0; left--)
	{
		temp[j++] = buffer[left];
	}
	temp[_strlen(buffer)] = '\0';
	for (i = 0; temp[i] != '\0'; i++)
	{
		buffer[i] = temp[i];
	}
	buffer[i] = '\0';
}
