/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** main
*/

#include <stdlib.h>
#include <string.h>

int print_help(int ret)
{
    printf("./generator x y [perfect]\n\n");
    printf("x: width of the maze (must be > 0)\n");
    printf("y: heigh of the maze (must be > 0)\n");
    printf("[Perfect]: should the maze be perfect ?\n");
    return (ret);
}

int main(int ac, char **av)
{
    int x = 0;
    int y = 0;

    if (ac < 3)
        return (print_help(0));
    x = atoi(av[1]);
    y = atoi(av[2]);
    if (x <= 0 || y <= 0)
        return (print_help(84));
    if (ac >= 4 && strcmp("perfect", av[3]) == 0)
        generate_perfect_maze(x, y);
    else
        generate_imperfect_maze(x, y);
}