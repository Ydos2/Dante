/*
** EPITECH PROJECT, 2020
** dante
** File description:
** dante
*/

#include <stdlib.h>
#include "libmy.h"
#include "dante.h"

void get_neighbours_pos(t_open *neighbor, int y, int x)
{
    neighbor->y = y;
    neighbor->x = x;
}

int set_neighbours(t_open *neighbor,
    t_map *map, t_first *f, t_open *actual)
{
    int ret = 0;

    if (neighbor->x >= 0 && neighbor->x < map->largeur
        && neighbor->y >= 0 && neighbor->y < map->hauteur
        && map->map[neighbor->y][neighbor->x] != 'X'
        && (ret = is_it_closed(f, neighbor->y, neighbor->x)) != 1) {
        if (ret == -1)
            return (1);
        if ((ret = is_it_in_open(f, neighbor->y, neighbor->x)) != 1) {
            if (ret == -1)
                return (1);
            neighbor->closed = 0;
            neighbor->h_cost = ((map->largeur - 1)- neighbor->x) * 10
            + ((map->hauteur - 1) - neighbor->y) * 10;
            neighbor->parent = actual;
            if (add_neighbor_in_open(f, neighbor) == 1)
                return (1);
        }
    }
    return (0);
}

void map_loop(t_open *actual, t_map *map)
{
    while (actual != NULL) {
        map->map[actual->y][actual->x] = 'o';
        actual = actual->parent;
    }
}

int dante(t_map *map, t_first *f)
{
    t_open *actual;

    while (count_open(f) > 0) {
        actual = lowest_h_cost(f);
        if (actual == NULL)
            return (1);
        close_actual_from_open(f, actual);
        if (actual->y == map->hauteur - 1 && actual->x == map->largeur - 1) {
            map_loop(actual, map);
            return (0);
        }
        if (get_neighbours(map, f, actual) == 1)
            return (1);
    }
    return (1);
}