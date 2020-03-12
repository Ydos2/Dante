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
        maze[i] = malloc(sizeof(char) * (x + 2));
        for (; j != x; j++)
            maze[i][j] = 'X';
        maze[i][j] = '\0';
    }
    maze[y] = NULL;
    maze[0][0] = '*';
    maze[y - 1][x - 1] = '*';
    return (maze);
}