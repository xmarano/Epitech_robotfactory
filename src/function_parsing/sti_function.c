/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-robotfactory-arnaud.jouan
** File description:
** sti_function.c
*/
#include "../rf.h"
#include "../my.h"

static int sti_param1(S_t *s)
{
    if (s->arr[1][0] != 'r' || s->arr[1][1] < '0' || s->arr[1][1] > '9'
    || s->arr[1][2] != ',' || s->arr[1][3] != '\0')
        return 84;
    return 0;
}

static int sti_param2(S_t *s)
{
    if (s->arr[2][0] != 'r' && s->arr[2][0] != '%')
        return 84;
    if (s->arr[2][0] == 'r' && (s->arr[2][1] < '0' || s->arr[2][1] > '9'
    || s->arr[2][2] != ',' || s->arr[2][3] != '\0'))
            return 84;
    if (s->arr[2][0] == '%' && (s->arr[2][1] != ':' || (s->arr[2][2] == ',')))
        return 84;
    if (s->arr[2][my_strlen(s->arr[2]) - 1] != ','
    || s->arr[2][my_strlen(s->arr[2])] != '\0')
        return 84;
    for (int i = 2; s->arr[2][i] != ','; i++) {
        if (s->arr[2][0] == '%' && (s->arr[2][i] < 'a' || s->arr[2][i] > 'z'))
            return 84;
    }
    return 0;
}

static int sti_param3(S_t *s)
{
    if (s->arr[3][0] != 'r' && s->arr[3][0] != '%')
        return 84;
    for (int i = 1; s->arr[3][i] != '\0'; i++) {
        if (s->arr[3][0] == '%' && (s->arr[3][i] < '0' || s->arr[3][i] > '9'))
            return 84;
    }
    if (s->arr[3][0] == 'r' && s->arr[3][1] < '0' || s->arr[3][1] > '9')
        return 84;
    if (s->arr[3][0] == 'r' && s->arr[3][2] != '\0')
        return 84;
    return 0;
}

int sti_function(S_t *s)
{
    for (int i = 0; s->arr[i] != NULL; i++) {
        if (s->arr[i + 1] == NULL && i != 3)
            return 84;
    }
    if (sti_param1(s) == 84)
        return 84;
    if (sti_param2(s) == 84)
        return 84;
    if (sti_param3(s) == 84)
        return 84;
    return 0;
}
