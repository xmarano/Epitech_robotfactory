/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-robotfactory-arnaud.jouan
** File description:
** error_body.c
*/
#include "rf.h"
#include "my.h"

int all_parameters(S_t *s)
{
    if (s->arr[0] == NULL)
        return 0;
    if (my_strcmp(s->arr[0], "sti") == 0)
        return sti_function(s);
    return 0;
}

int error_body(int argc, char **argv, S_t *s)
{
    FILE *file;
    char *str = NULL;
    size_t len = 0;
    ssize_t read;

    file = fopen(argv[1], "r");
    for (int i = 0; i != 3; i++)
        read = getline(&str, &len, file);
    if (my_strcmp(str, "\n") != 0)
        return 84;
    while (read != -1) {
        read = getline(&str, &len, file);
        s->arr = str_to_word_array(str);
        if (all_parameters(s) == 84)
            return 84;
    }
    free(str);
    fclose(file);
    return 0;
}
