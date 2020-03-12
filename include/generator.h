/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <stdbool.h>

bool **create_wandering_path(int x, int y);
char **create_empty_maze(int x, int y);
void add_perfect_path(char **maze, bool **path, int x, int y);
void generate_perfect_maze(int x, int y);
void generate_imperfect_maze(int x, int y);

#endif /* !GENERATOR_H_ */