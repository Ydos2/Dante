/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "dante.h"

static int my_strcmpp(char const *s1, char const *s2)
{
    int i = 0;

    while ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]))
        i++;
    if (s1[i] < s2[i])
        return (-1);
    else if (s2[i] < s1[i])
        return (1);
    else
        return (0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (my_strcmpp(av[1], "-h") == 0) {
        draw_help();
        return (0);
    }
    return (start_dante(av));
}