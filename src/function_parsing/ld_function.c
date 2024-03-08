/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-robotfactory-arnaud.jouan
** File description:
** ld_function.c
*/
#include "../rf.h"
#include "../my.h"

static int ld_param1(S_t *s)
{
    if (s->arr[1][0] != '%' || s->arr[1][my_strlen(s->arr[1]) - 1] != ',')
        return 84;
    if (s->arr[1][1] == ',')
        return 84;
    for (int i = 1; s->arr[1][i] != ','; i++) {
        if (s->arr[1][i] < '0' || s->arr[1][i] > '9')
            return 84;
    }
    return 0;
}

static int ld_param2(S_t *s)
{
    if (s->arr[2][0] != 'r' || s->arr[2][1] < '0' || s->arr[1][1] > '9'
    || s->arr[2][2] != '\0')
        return 84;
    return 0;
}

int ld_function(S_t *s)
{
    for (int i = 0; s->arr[i] != NULL; i++) {
        if (s->arr[i + 1] == NULL && i != 2)
            return 84;
    }
    if (ld_param1(s) == 84)
        return 84;
    if (ld_param2(s) == 84)
        return 84;
    return 0;
}
