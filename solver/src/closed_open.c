/*
** EPITECH PROJECT, 2020
** closed_open
** File description:
** closed_open
*/

#include "dante.h"

int closed_loop(t_open *tmp, int x, int y)
{
    while (tmp != NULL) {
        if (y == tmp->y && x == tmp->x && tmp->closed == 1)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

int is_it_closed(t_first *f, int y, int x)
{
    t_open *tmp;
    int i = 0;

    if (f != NULL) {
        tmp = f->first;
        i = closed_loop(tmp, x, y);
        return (i);
    }
    return (-1);
}

int open_loop(t_open *tmp, int x, int y, t_first *f)
{
    tmp = f->first;
    while (tmp != NULL) {
        if (y == tmp->y && x == tmp->x && tmp->closed == 0)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

int is_it_in_open(t_first *f, int y, int x)
{
    t_open *tmp;
    int i = 0;

    if (f != NULL) {
        i = open_loop(tmp, x, y, f);
        return (i);
    }
    return (-1);
}