/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** create_empty_maze
*/

#include "stdlib.h"

char **create_empty_maze(int x, int y)
{
    char **maze = NULL;
    int i = 0;
    int j = 0;

    maze = malloc(sizeof(char *) * (y + 1));
    if (!maze)
        return (NULL);
    for (; i != y + 1; i++) {
        j = 0;
        maze[i] = malloc(sizeof(char) * (x + 1));
        for (; j != x + 1; j++)
            maze[i][j] = 'x';
        maze[i][j] = i != j ? '\n' : '\0';
    }
    maze[y] = NULL;
    return (maze);
}