#include "shell.h"
/**
 * _memset - creating function to fill memory with byte
 * @s: passed pointer
 * @b: passed char representing constate byte
 * @n: integer representing number bytes to be filled
 * Return: char
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
