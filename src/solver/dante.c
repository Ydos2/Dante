/*
** EPITECH PROJECT, 2020
** dante
** File description:
** dante
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dante.h"
#include "libmy.h"

void draw_path(struc_t *struc, int entry)
{
    if (entry == 1) {
        if (struc->map[struc->y][struc->x+struc->factor] == 'o') {
            struc->map[struc->y][struc->x+struc->factor] = '*';
        }
    } else if (struc->map[struc->y][struc->x] == '*')
        struc->map[struc->y][struc->x] = 'o';
}

int analyse(struc_t *struc, int x, int y)
{
    if (x > struc->x_max || y > struc->y_max)
        return (0);
    if (struc->map[y][x] == '*')
        return (1);
    return (0);
}

int action_path(struc_t *struc, int x, int y, int entry)
{
    if (analyse(struc, x+1, y) == 1 && entry == 0) {
        struc->x += 1;
        return (1);
    }
    if (analyse(struc, x, y+1) == 1) {
        struc->y += 1;
        return (1);
    }
    if (analyse(struc, x, y-1) == 1) {
        struc->y -= 1;
        return (1);
    }
    if (analyse(struc, x-1, y) == 1) {
        struc->x -= 1;
        return (1);
    }
    return (0);
}

char **ai_brain(struc_t *struc, int entry)
{
    draw_path(struc, entry);
    if (struc->y == struc->y_max && struc->x == struc->x_max-1)
        return (struc->map);
    if (action_path(struc, struc->x, struc->y, entry) == 1)
        return (ai_brain(struc, 0));
    else {
        struc->x--;
        return (ai_brain(struc, 1));
    }
}

int start_dante(char **av)
{
    char **map = NULL;
    struc_t *struc = NULL;

    if (av == NULL)
        return (84);
    map = read_file(av[1]);
    struc = initialise_arg(struc, map);
    map = ai_brain(struc, 0);
    for (int y = 0; map[y] != NULL; y++)
        puts(map[y]);
    my_free_array(struc->map);
    free(struc);
    return (0);
}