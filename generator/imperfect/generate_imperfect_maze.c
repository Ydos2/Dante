/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** generate_imperfect_m
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "generator.h"

void generate_imperfect_maze(int x, int y)
{
    char **m = create_empty_maze(x, y);
    bool **path = create_wandering_path(x, y);
    int i = 0;
    int j = 0;

    add_perfect_path(m, path, x, y);
    for (; m[i] != NULL; i++) {
        for (; m[i][j] != '\0'; j++)
            m[i][j] = m[i][j] == 'X' && rand() % 100 <= 25 ? '*' : m[i][j];
        j = 0;
    }
    i = 0;
    for (; m[i + 1] != NULL; i++) {
        printf("%s\n", m[i]);
        free(m[i]);
        free(path[i]);
    }
    write(1, m[i], strlen(m[i]));
    free(m);
    free(path);
}