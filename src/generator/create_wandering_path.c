/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** create_wandering_path
*/

#include <stdlib.h>
#include <stdbool.h>

bool **create_wandering_path(int x, int y)
{
    bool **path = NULL;
    int i = 0;
    int j = 0;

    path = malloc(sizeof(bool *) * (y + 1));
    if (!path)
        return (NULL);
    for (; i != y + 1; i++) {
        j = 0;
        path[i] = malloc(sizeof(bool) * (x + 1));
        for (; j != x; j++)
            path[i][j] = false;
    }
    path[y] = NULL;
    path[0][0] = true;
    path[y - 1][x - 1] = true;
    return (path);
}