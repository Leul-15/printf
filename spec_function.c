#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * rot13_find - encodes a string using rot13
 * @s: string to encode
 * Return: encoded to rot13
 */

char *rot13_find(va_list s)
{
	int i, x, temp, len;
	char check[] = "AaZz";
	char ntom[] = "NOPQRSTUVWXYZABCDEFGHIJKLM";
	char *arg, *rot;

	arg = va_arg(s, char *);
	if (arg == NULL)
		return (NULL);
	len = _strlen(arg);
	rot = malloc((len + 1) * sizeof(char));
	if (rot == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		for (x = 0; x < 2; x++)
		{
			if (arg[i] >= check[x] && arg[i] <= check[x + 2])
			{
				temp = (arg[i] - 65 - (x * 32));
				rot[i] = (ntom[temp] + (x * 32));
				break;
			}
			else if (!(arg[i] >= check[x + 1] && arg[i] <= check[x + 3]))
			{
				rot[i] = arg[i];
				break;
			}
		}
	rot[i] = '\0';
	return (rot);
}
/**
 * rev_find - reverse a string
 * @s: input string
 * Return: reversed string
 */
char *rev_find(va_list s)
{
	char *arg, *rev;
	int i, len;

	arg = va_arg(s, char *);
	if (arg == NULL)
		return (NULL);
	len = _strlen(arg);
	rev = malloc((len + 1) * sizeof(char));
	if (rev == NULL)
		return (NULL);
	len--;
	for (i = 0; len >= 0; i++, len--)
		rev[i] = arg[len];
	rev[i] = '\0';
	return (rev);
}

/**
 * binary_find - converts a string to binary
 * @n: input string
 * Return: binary string
 */
char *binary_find(va_list n)
{
	int i, j;
	int binaryNum[32], arg;
	char *binaryString;

	arg = va_arg(n, int);
	for (i = 0; arg > 0; i++, arg /= 2)
		binaryNum[i] = arg % 2;
	binaryString = malloc(i * sizeof(char));
	if (binaryString == NULL)
		return (NULL);
	for (j = 0, i -= 1; i >= 0; i--, j++)
		binaryString[j] = (binaryNum[i] + '0');
	return (binaryString);
}

/**
 * octal_find - converts decimal to octal numbers
 * @n: octal number to print
 * Return: pointer to string
 */

char *octal_find(va_list n)
{
	unsigned long int pos, temp, result, oct, i;
	char *string;

	oct = va_arg(n, unsigned long int);
	result = i = 0;
	pos = 1;
	while (oct)
	{
		result += (oct % 8) * pos;
		oct /= 8;
		pos *= 10;
		i++;
	}
	temp = i;
	pos /= 10;
	string = malloc(temp * sizeof(char) + 1);
	if (string == NULL)
		return (NULL);
	for (i = 0 ; i < temp; i++)
	{
		string[i] = ((result / pos) % 10) + '0';
		pos /= 10;
	}
	string[i] = '\0';
	return (string);
}
