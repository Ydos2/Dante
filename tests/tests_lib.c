/*
** EPITECH PROJECT, 2020
** tests_lib
** File description:
** tests_lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "dante.h"
#include "libmy.h"

Test(test_lib, my_strcmp_test, .timeout = 1)
{
    int nbr = 0;

    nbr = my_strcmpp("-h", "-h");
    cr_assert_eq(nbr, 0);
}