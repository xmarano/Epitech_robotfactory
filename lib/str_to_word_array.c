/*
** EPITECH PROJECT, 2023
** str_to_word_array.c
** File description:
** Infos
*/
#include "../src/my.h"

int is_alphanum2(char c)
{
    if (c <= '!' || c >= 127)
        return (0);
    return (1);
}

char **str_to_word_array(char *str)
{
    int x = 0;
    int i = 0;
    int size = 0;
    char **arr = malloc(sizeof(char *) * (50));

    while (str[i] != '\0') {
        if (is_alphanum2(str[i]))
            size++;
        if (is_alphanum2(str[i]) == 1 && is_alphanum2(str[i + 1]) == 0) {
            arr[x] = malloc(sizeof(char) * (size + 1));
            my_strncpy(arr[x], &str[i - size + 1], size);
            size = 0;
            x++;
        }
        i++;
    }
    arr[x] = NULL;
    return (arr);
}
