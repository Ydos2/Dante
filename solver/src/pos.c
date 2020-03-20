/*
** EPITECH PROJECT, 2020
** pos
** File description:
** pos
*/

#include <stdlib.h>
#include "dante.h"

void switch_pos(int i, t_open *actual, t_open *neighbor)
{
    switch (i) {
        case 0:
            get_neighbours_pos(neighbor, actual->y, actual->x - 1);
            break;
        case 1:
            get_neighbours_pos(neighbor, actual->y, actual->x + 1);
            break;
        case 2:
            get_neighbours_pos(neighbor, actual->y - 1, actual->x);
            break;
        case 3:
            get_neighbours_pos(neighbor, actual->y + 1, actual->x);
            break;
    }
}

int get_neighbours(t_map *map, t_first *f, t_open *actual)
{
    t_open *neighbor;

    for (int i = 0; i < 4; i++) {
        neighbor = malloc(sizeof(t_open));
        if (neighbor == NULL)
            return (1);
        switch_pos(i, actual, neighbor);
        if (set_neighbours(neighbor, map, f, actual) == 1)
            return (1);
    }
    return (0);
}

t_open *cost(t_first *f, int save_i, int min, t_open *tmp)
{
    tmp = f->first;
    min = get_min(f);
    if (min == -1)
        return (NULL);
    for (int i = 0; tmp != NULL; i++) {
        if (tmp->closed == 0 && min >= tmp->h_cost) {
            save_i = i;
            min = tmp->h_cost;
        }
        tmp = tmp->next;
    }
    return (return_actual(f, save_i));
}

t_open *lowest_h_cost(t_first *f)
{
    int save_i = 0;
    int min;
    t_open *tmp;

    if (f != NULL && f->first != NULL)
        return (cost(f, save_i, min, tmp));
    return (NULL);
}