/*
** EPITECH PROJECT, 2019
** help_page.c
** File description:
** navy's help_page
*/

#include <unistd.h>

void draw_help(void)
{
    write(1, "USAGE\n", 6);
    write(1, "\t./navy [first_player_pid] navy_positions\n", 42);
    write(1, "DESCRIPTION\n", 12);
    write(1, "\tfirst_player_pid:  only for the 2nd player.", 44);
    write(1, "  pid of the first player.\n", 27);
    write(1, "\tnavy_positions:  file representing", 35);
    write(1, " the positions of the ships.\n", 29);
}