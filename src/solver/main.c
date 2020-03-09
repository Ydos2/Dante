/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "dante.h"
#include "libmy.h"

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