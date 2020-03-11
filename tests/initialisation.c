/*
** EPITECH PROJECT, 2019
** initialisation
** File description:
** initialisation
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "dante.h"
#include "libmy.h"

Test(initialise_var_start, test_structure_1, .timeout = 1)
{
    struc_t *struc = NULL;

    struc = initialise_arg(struc, NULL);
    cr_assert_eq(struc->x, 0);
}

Test(dante_start, test_dante_1, .timeout = 1)
{
    int nbr = 0;

    nbr = start_dante(NULL);
    cr_assert_eq(nbr, 84);
}