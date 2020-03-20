/*
** EPITECH PROJECT, 2020
** map
** File description:
** map
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libmy.h"
#include "dante.h"

void print_map(t_map *map)
{
    for (int i = 0; i != map->hauteur; i++) {
        my_putstrr(map->map[i]);
        write(1, "\n", 1);
    }
}

int detect_error(char *line, int largeur)
{
    int i = 0;

    if ((int)my_strlenn(line) != largeur)
        return (1);
    while (line[i] != '\0') {
        if (line[i] != '*' && line[i] != 'X')
            return (1);
        i++;
    }
    return (0);
}

int stock_map(t_map *map, char *av)
{
    int i = 0;
    FILE *fd = fopen(av, "r");
    size_t len = 0;
    char *str = NULL;

    if (fd == NULL)
        return (1);
    while (getline(&str, &len, fd) != -1) {
        map->map[i] = my_strdupp(str);
        map->map[i][map->largeur] = '\0';
        if (detect_error(map->map[i], map->largeur) == 1)
            return (1);
        i++;
    }
    fclose(fd);
    return (0);
}

int get_map(t_map *map, char *av)
{
    FILE *fd = fopen(av, "r");
    char *str = NULL;
    size_t len = 0;

    map->hauteur = 0;
    if (fd == NULL)
        return (1);
    while (getline(&str, &len, fd) != -1)
        map->hauteur = map->hauteur + 1;
    map->largeur = my_strlenn(str) - 1;
    fclose(fd);
    map->map = malloc(sizeof(char *) * map->hauteur);
    if (map->map == NULL)
        return (1);
    if (stock_map(map, av) == 1)
        return (1);
    return (0);
}