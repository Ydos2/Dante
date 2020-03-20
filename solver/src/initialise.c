/*
** EPITECH PROJECT, 2020
** initialise
** File description:
** initialise
*/

#include <stdlib.h>
#include "libmy.h"
#include "dante.h"

int add_neighbor_in_open(t_first *f, t_open *neighbor)
{
    if (f != NULL) {
        neighbor->next = f->first;
        f->first = neighbor;
        return (0);
    }
    return (1);
}

int count_open(t_first *f)
{
    int nb_cells = 0;
    t_open *tmp;

    if (f != NULL) {
        tmp = f->first;
        while (tmp != NULL) {
            if (tmp->closed == 0)
                nb_cells++;
        tmp = tmp->next;
        }
    }
    return (nb_cells);
}

t_first *init_first(t_map *map)
{
    t_first *f = malloc(sizeof(t_first));
    t_open *open = malloc(sizeof(t_open));

    if (f == NULL || open == NULL)
        return (NULL);
    if (f == NULL || open == NULL)
        return (NULL);
    open->x = 0;
    open->y = 0;
    open->h_cost = (map->largeur - 1) * 10 + (map->hauteur - 1) * 10;
    open->closed = 0;
    open->next = NULL;
    open->parent = NULL;
    f->first = open;
    return (f);
}