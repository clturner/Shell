#include"shell.h"
/**
 * _strlen - prints length string in integer
 * @s: string passed to function
 * Return: length of string
 */
int _strlen(const char *s)
{
	int a = 0;

	while (*(s + a))
		a++;
	return (a);
}
/**
 * _strdup - function returns pointer to new string
 * @str: string that is being passed
 * Return: pointer
 */
char *_strdup(const char *str)
{
	char *str2;
	int i;
	int length;

	if (str == NULL)
	{
		return (NULL);
	}
	length = _strlen(str);
	str2 = malloc((length + 1) * sizeof(const char));
	i = 0;
	while (i < length)
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
/**
 * _strcat - adding one string to the end of another
 * @dest: destination string
 * @src: string to be added
 * Return: char
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);
}
/**
 * _strcmp - function to compare strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: integer
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
/**
 * _strcpy - function to copy string to new dest
 * @dest: where the string is being assigned
 * @src: where it is coming from
 * Return: pointer to destination
 */
char *_strcpy(char *dest, const char *src)
{
	int i;
	int length;

	length = _strlen(src);
	for (i = 0; i < length + 1; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
