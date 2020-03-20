/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** Dups a string
*/

#include <stdlib.h>
#include "libmy.h"

char *my_strdup(char *src)
{
    char *dest = malloc(sizeof(char) * my_strlen(src) + 1);

    if (dest == NULL)
        return (NULL);
    my_strcpy(dest, src);
    return (dest);
}