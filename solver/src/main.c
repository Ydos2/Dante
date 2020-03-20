/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include "libmy.h"
#include "dante.h"

void free_struct(t_map *map)
{
    for (int i = 0; i != map->hauteur; i++)
        free(map->map[i]);
    free(map->map);
}

int main(int ac, char **av)
{
    t_map map;
    t_first *f = NULL;

    if (ac != 2)
        return (1);
    if (!my_strcmp(av[1], "-h")) {
        draw_help();
        return (0);
    }
    if (get_map(&map, av[1]) == 1)
        return (1);
    f = init_first(&map);
    if (f == NULL)
        return (1);
    if (dante(&map, f) == 1)
        return (1);
    print_map(&map);
    free_struct(&map);
    return (0);
}