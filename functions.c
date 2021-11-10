#include "main.h"
/**
 * convert_base - Convert base and add argument in the buffer
 * @base: Number of base to convert
 * @number: Number to convert
 * @band: Flag with order to follow
 * @add: A pointer pointing to a memory address within the buffer
 *
 * Return: length of string added to buffer
 */
int convert_base(int base, long int number, int band, char **add)
{
	char buffer[17];
	char buffersito[20];
	char *ptr = &buffersito[20];
	long int save = number, len_end = 0;

	if (band == 0 || band == 2)
		_strcpy(buffer, "0123456789ABCDEF");
	else
		_strcpy(buffer, "0123456789abcdef");
	*ptr = '\0', ptr--;

	if (number == 0)
	{
		**add = 48, (*add)++;/*_putchar(48);*/
		return (1);
	}
	if (number < 0)
		number = -number;
	while (number > 0)
	{
		*ptr-- = buffer[number % base];
		number = number / base;
	}
	if (save < 0)
		*ptr-- = '-';
	if (band == 16)
		*ptr-- = 'x', *ptr-- = '0';
	ptr++;
	if (_strlen(ptr) < 2 && band == 2)
		**add = 0, (*add)++, len_end++; /*_putchar('0');*/
	len_end += _strlen(ptr);
	while (len_end > 0)
	{
		**add = *ptr;
		ptr++;
		(*add)++;
		len_end--;
	}
	return (0);
}
/**
 * print_number - prints an integer.
 * @n: integer n to print using _putchar
 * @add: A pointer pointing to a memory address within the buffer
 *
 * Return: none - void function
 */
int print_number(long int n, char **add)
{
	unsigned int r;
	int _length = 0;

	if (n < 0)
	{
		**add = 45;
		(*add)++;
		/*_putchar(45);*/
		n *= -1;
		_length++;
	}
	r = n;

	if (r / 10)
	{
		_length += print_number(r / 10, add);
	}
	**add = r % 10 + '0';
	(*add)++;
	/*_putchar(r % 10 + '0');*/
	return (0);
}
