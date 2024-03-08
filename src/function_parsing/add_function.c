/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-robotfactory-arnaud.jouan
** File description:
** add_function.c
*/
#include "../rf.h"
#include "../my.h"

static int add_param1(S_t *s)
{
    if (s->arr[1][0] != 'r' || s->arr[1][1] < '0' || s->arr[1][1] > '9'
    || s->arr[1][2] != ',' || s->arr[1][3] != '\0')
        return 84;
    return 0;
}

static int add_param2(S_t *s)
{
    if (s->arr[2][0] != 'r' || s->arr[2][1] < '0' || s->arr[1][1] > '9'
    || s->arr[2][2] != ',' || s->arr[2][3] != '\0')
        return 84;
    return 0;
}

static int add_param3(S_t *s)
{
    if (s->arr[3][0] != 'r' || s->arr[3][1] < '0' || s->arr[3][1] > '9'
    || s->arr[3][2] != '\0')
        return 84;
    return 0;
}

int add_function(S_t *s)
{
    for (int i = 0; s->arr[i] != NULL; i++) {
        if (s->arr[i + 1] == NULL && i != 3)
            return 84;
    }
    if (add_param1(s) == 84)
        return 84;
    if (add_param2(s) == 84)
        return 84;
    if (add_param3(s) == 84)
        return 84;
    return 0;
}
