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

typedef struct struc
{
    int x_max;
    int y_max;
    int x;
    int y;
    int factor;
    int factor_x;
    int factor_y;
    char **map;
} struc_t;

// help_page.c
void draw_help(void);

// dante.c
int start_dante(char **av);

// initialise.c
struc_t *initialise_arg(struc_t *struc, char **map);
void my_free_array(char **array);

// read_file.c
char **stock_line_in_array(char **last_stock, char *line, int line_size);
char **read_from_stream(FILE *stream);
char **read_file(char *path);

#endif /* !dante_H */