/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

#include <stdio.h>
#include <stdlib.h>
#include "dante.h"
#include "libmy.h"

char **stock_line_in_array(char **last_stock, char *line, int line_size)
{
    char **new;
    int line_nb = 0;
    int j = 0;

    for (; last_stock != NULL && last_stock[line_nb] != NULL; line_nb++);
    new = malloc(sizeof(char *) * (line_nb + 2));
    for (int i = 0; last_stock != NULL && last_stock[i] != NULL; i++)
        new[i] = last_stock[i];
    free(last_stock);
    new[line_nb] = malloc(sizeof(char) * line_size + 2);
    for (; line[j] != '\0' && line[j] != '\n'; j++)
        new[line_nb][j] = line[j];
    new[line_nb][j] = '\0';
    new[line_nb + 1] = NULL;
    return (new);
}

char **read_from_stream(FILE *stream)
{
    char *buffer = NULL;
    char **map = NULL;
    size_t size = 0;
    int line = 0;

    while ((size = getline(&buffer, &size, stream)) != -1) {
        map = stock_line_in_array(map, buffer, size);
        free(buffer);
        buffer = NULL;
        line++;
    }
    free(buffer);
    return (map);
}

char **read_file(char *path)
{
    char **map = NULL;
    FILE *stream;

    if (path == NULL)
        return (NULL);
    stream = fopen(path, "r");
    if (stream == NULL)
        return (NULL);
    map = read_from_stream(stream);
    fclose(stream);
    return (map);
}