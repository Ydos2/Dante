/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

#include <stdlib.h>
#include "libmy.h"
#include "dante.h"

int get_min(t_first *f)
{
    t_open *tmp;

    tmp = f->first;
    while (tmp != NULL && tmp->closed != 0)
        tmp = tmp->next;
    if (tmp == NULL)
        return (-1);
    if (tmp->closed == 0)
        return (tmp->h_cost);
    return (-1);
}

t_open *return_actual(t_first *f, int save_i)
{
    int i = 0;
    t_open *tmp;

    tmp = f->first;
    while (tmp != NULL && i != save_i) {
        i++;
        tmp = tmp->next;
    }
    return (tmp);
}

t_first *close_actual_from_open(t_first *f, t_open *actual)
{
    t_open *tmp;

    if (f == NULL || actual == NULL)
        return (NULL);
    tmp = f->first;
    while (tmp != NULL) {
        if (tmp->x == actual->x && tmp->y == actual->y) {
            tmp->closed = 1;
            return (f);
        }
        tmp = tmp->next;
    }
    return (NULL);
}