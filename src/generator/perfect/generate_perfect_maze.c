/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** generate_perfect_maze
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "generator.h"

void generate_perfect_maze(int x, int y)
{
    char **maze = create_empty_maze(x, y);
    bool **path = create_wandering_path(x, y);
    int i = 0;

    add_perfect_path(maze, path, x, y);
    for (; maze[i + 1] != NULL; i++) {
        printf("%s\n", maze[i]);
        free(maze[i]);
        free(path[i]);
    }
    write(1, maze[i], strlen(maze[i]));
    free(maze);
    free(path);
}