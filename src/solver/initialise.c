/*
** EPITECH PROJECT, 2020
** initialise
** File description:
** initialise
*/

#include <string.h>
#include "dante.h"
#include "libmy.h"

struc_t *initialise_arg(struc_t *struc, char **map)
{
    struc = malloc(sizeof(struc_t));
    int y = 0;

    struc->map = map;
    for (; map[y] != NULL; y++);
    y--;
    struc->y_max = y;
    struc->x_max = strlen(map[y]);
    struc->x = 0;
    struc->y = 0;
    return (struc);
}

void my_free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}