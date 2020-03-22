/*
** EPITECH PROJECT, 2020
** dante
** File description:
** dante
*/


#include <stdio.h>
#include <stdlib.h>
#ifndef DANTE_H_
#define DANTE_H_

typedef struct s_open
{
    int x;
    int y;
    int h_cost;
    int closed;
    struct s_open *next;
    struct s_open *parent;
} t_open;

typedef struct s_first
{
    t_open *first;
} t_first;

typedef struct s_map
{
    int hauteur;
    int largeur;
    char **map;
} t_map;

// dante.c
void get_neighbours_pos(t_open *neighbor, int y, int x);
int set_neighbours(t_open *neighbor,
    t_map *map, t_first *f, t_open *actual);
void map_loop(t_open *actual, t_map *map);
int dante(t_map *map, t_first *f);

// pos.c
int get_neighbours(t_map *map, t_first *f, t_open *actual);
t_open *lowest_h_cost(t_first *f);

// help_page.c
void draw_help(void);

// initialise.c
int add_neighbor_in_open(t_first *f, t_open *neighbor);
int count_open(t_first *f);
t_first *init_first(t_map *map);

// map.c
void print_map(t_map *map);
int detect_error(char *line, int largeur);
int stock_map(t_map *map, char *av);
int get_map(t_map *map, char *av);

// read_file.c
int get_min(t_first *f);
t_open *return_actual(t_first *f, int save_i);
t_first *close_actual_from_open(t_first *f, t_open *actual);
int is_it_closed(t_first *f, int y, int x);
int is_it_in_open(t_first *f, int y, int x);

// tools_function.c
char *my_strdupp(char *src);
int my_strlenn(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_putstrr(char const *str);

#endif /* !dante_H */