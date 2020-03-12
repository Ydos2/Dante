/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** add_perfect_path
*/

#include <stdlib.h>
#include <stdbool.h>
#include "vector.h"
#include <time.h>

///////////////////////////////////////////////////////////////////
// Exhautive Exploration                                         //
//                                                               //
// If two paths next to the check cell are already explored ('*')//
// Then a path can't be opened or it would be an unperfect maze. //
///////////////////////////////////////////////////////////////////

bool check_openable(char **maze, bool **path, vector2_t *pos, vector2_t check)
{
    int pass = 0;

    if (check.y < 0 || !maze[check.y] || check.x < 0)
        return (false);
    if (maze[check.y][check.x] != 'X')
        return (false);
    if (maze[check.y][check.x] == '\n' || maze[check.y][check.x] == '\0')
        return (false);
    pass += check.y > 0 && maze[check.y - 1][check.x] == '*';
    pass += maze[check.y + 1] && maze[check.y + 1][check.x] == '*';
    pass += check.x > 0 && maze[check.y][check.x - 1] == '*';
    pass += maze[check.y][check.x + 1] == '*';
    if (pass == 1) {
        pos->y = check.y;
        pos->x = check.x;
    }
    path[check.y][check.x] = true;
    maze[check.y][check.x] = pass == 1 ? '*' : 'X'; 
    return (pass == 1);
}

bool open_next_tile(char **maze, bool **path, vector2_t *pos)
{
    int chance = rand() % 100;

    for (int odds = 25; odds != 125; odds += 25) {
        if (chance <= odds &&
        check_openable(maze, path, pos, (vector2_t){pos->x + 1, pos->y}))
            return (true);
        chance = rand() % 100;
        if (chance <= odds &&
        check_openable(maze, path, pos, (vector2_t){pos->x, pos->y + 1}))
            return (true);
        chance = rand() % 100;
        if (chance <= odds &&
        check_openable(maze, path, pos, (vector2_t){pos->x - 1, pos->y}))
            return (true);
        chance = rand() % 100;
        if (chance <= odds &&
        check_openable(maze, path, pos, (vector2_t){pos->x, pos->y - 1}))
            return (true);
    }
    path[pos->y][pos->x] = true;
    return (false);
}

bool move_to_next_tile(bool **path, vector2_t *pos, vector2_t max)
{
    static int x = 0;
    static int y = 0;

    for (; path[y][x] == true; x++) {
        if (x == max.x - 1) {
            x = 0;
            y++;
        }
        if (y == max.y)
            break;
    }
    pos->x = x;
    pos->y = y;
    return (y != max.y) ? true : false;
}

bool check_end(char **maze, vector2_t pos, vector2_t max)
{
    if (pos.x == max.x && pos.y + 2 == max.y) {
        maze[max.y - 1][max.x] = '*';
        return (true);
    } else if (pos.y == max.y && pos.x + 2 == max.x) {
        maze[max.y][max.x - 1] = '*';
        return (true);
    }
    return (false);
}

void add_perfect_path(char **maze, bool **path, int x, int y)
{
    vector2_t pos = {0, 0};
    vector2_t max_pos = {x, y};
    bool can_continue = true;
    bool has_end = false;

    max_pos.y -= 1;
    max_pos.x -= 1;
    srand(time(NULL));
    while (can_continue) {
        can_continue = open_next_tile(maze, path, &pos);
        path[pos.y][pos.x] = true;
        if (!has_end && can_continue)
            has_end = check_end(maze, pos, max_pos);
        if (!can_continue)
            can_continue = move_to_next_tile(path, &pos, max_pos);
    }
}