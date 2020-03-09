/*
** EPITECH PROJECT, 2020
** dante
** File description:
** dante
*/

#include "dante.h"
#include "libmy.h"

int start_dante(char **av)
{
    char *map = my_parsing(av[1]);

    puts(map);
    return (0);
}