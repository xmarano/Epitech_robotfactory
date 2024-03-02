/*
** EPITECH PROJECT, 2023
** cpoolday06
** File description:
** Infos
*/
#include <stddef.h>
char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && n > i) {
        dest[i] = src[i];
        i++;
    }
    if (i < n) {
        dest[i] = '\0';
    }
    return dest;
}
