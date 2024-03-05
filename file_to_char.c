/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-robotfactory-arnaud.jouan
** File description:
** file_to_char.c
*/
#include "rf.h"
#include "op.h"
#include "my.h"

static void name_in_char(int argc, char **argv, char *str, header_t *h)
{
    int nb = 0;
    int nb2 = 0;
    int nb3 = 0;

    for (int i = 0; str[i] != '"'; i++)
        nb = i + 2;
    for (int i = nb; str[i] != '"'; i++)
        nb2 = i + 1;
    for (; nb < nb2; nb++) {
        h->prog_name[nb3] = str[nb];
        nb3++;
    }
    h->comment[nb3] = '\0';
}

static void comment_in_char(int argc, char **argv, char *str, header_t *h)
{
    int nb = 0;
    int nb2 = 0;
    int nb3 = 0;

    for (int i = 0; str[i] != '"'; i++)
        nb = i + 2;
    for (int i = nb; str[i] != '"'; i++)
        nb2 = i + 1;
    for (; nb < nb2 && str[nb] != '"'; nb++) {
        h->comment[nb3] = str[nb];
        nb3++;
    }
    h->comment[nb3] = '\0';
}

int file_to_char(int argc, char **argv, header_t *h)
{
    FILE *file;
    char *str = NULL;
    size_t len = 0;
    ssize_t read;

    file = fopen(argv[1], "r");
    read = getline(&str, &len, file);
    name_in_char(argc, argv, str, h);
    read = getline(&str, &len, file);
    comment_in_char(argc, argv, str, h);
    free(str);
    fclose(file);
    return 0;
}
