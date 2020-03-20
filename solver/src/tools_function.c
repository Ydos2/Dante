/*
** EPITECH PROJECT, 2020
** tools_function
** File description:
** tools_function
*/

#include <stdlib.h>
#include <unistd.h>
#include "dante.h"

char *my_strcpyy(char *dest, char *src)
{
    int z = 0;

    if (dest == NULL || src == NULL)
        return (NULL);
    for (; src[z] != '\0'; z++)
        dest[z] = src[z];
    dest[z] = '\0';
    return (dest);
}

char *my_strdupp(char *src)
{
    char *dest = malloc(sizeof(char) * my_strlenn(src) + 1);

    if (dest == NULL)
        return (NULL);
    my_strcpyy(dest, src);
    return (dest);
}

int my_strlenn(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]))
        i++;
    if (s1[i] < s2[i])
        return (-1);
    else if (s2[i] < s1[i])
        return (1);
    else
        return (0);
}

int my_putstrr(char const *str)
{
    if (str == NULL)
        return (84);
    write(1, str, my_strlenn(str));
    return (0);
}