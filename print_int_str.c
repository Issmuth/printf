#include "main.h"
/**
 * print_int_str - returns a string of chars which are int
 * @num: actual integer
 * @buffer: array of chars
 * Return: void; */ 
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
	/* handling zero values */
	if (num == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return;
	}
	/* incase on negative */
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	/*single data extraction*/
	while (num != 0)
	{
		buffer[i++] = '0' + num % 10;
		num /= 10;
	}
	/* add a sign if the number is negative */
	if (is_negative)
	{
		buffer[i++] = '-';
	}
	/* adding the end of line char */
	buffer[i] = '\0';
	/* reverse the values to get the actual value */
	
	for ( left = (_strlen(buffer) - 1); left >= 0; left--)
	{
		temp[j++] = buffer[left];
	}
	/**
	 * while (left < right)
	*{
	*	temp = buffer[left];
	*	buffer[left] = buffer[right];
	*	buffer[right] = temp;
	*	left++;
	*	right--;
	*}
	*/
	
	for (i = 0; temp[i] != '\0'; i++)
	{
		buffer[i] = temp[i];
	}
	/*printf("%d\n", buffer[i]);*/
}
