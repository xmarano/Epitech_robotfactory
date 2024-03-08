/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-robotfactory-arnaud.jouan
** File description:
** file_to_header.c
*/
#include "rf.h"
#include "op.h"
#include "my.h"

static void name_in_header(int argc, char **argv, char *str, header_t *h)
{
    int nb = 0;
    int nb2 = 0;
    int nb3 = 0;

    for (int i = 0; str[i] != '\"'; i++)
        nb = i + 2;
    for (int i = nb; str[i] != '\"'; i++)
        nb2 = i + 1;
    for (; nb < nb2; nb++) {
        h->prog_name[nb3] = str[nb];
        nb3++;
    }
    h->prog_name[nb3] = '\0';
    for (int i = my_strlen(h->prog_name); i < PROG_NAME_LENGTH; i++)
        h->prog_name[i] = '\0';
}

static void comment_in_header(int argc, char **argv, char *str, header_t *h)
{
    int nb = 0;
    int nb2 = 0;
    int nb3 = 0;

    for (int i = 0; str[i] != '\"'; i++)
        nb = i + 2;
    for (int i = nb; str[i] != '\"'; i++)
        nb2 = i + 1;
    for (; nb < nb2 && str[nb] != '\"'; nb++) {
        h->comment[nb3] = str[nb];
        nb3++;
    }
    h->comment[nb3] = '\0';
    for (int i = my_strlen(h->comment); i < COMMENT_LENGTH; i++)
        h->comment[i] = '\0';
}

static void size_in_header(char *str, header_t *h, S_t *s)
{
    h->prog_size = 0;
}

static int magic_in_header(int nb)
{
    return ((nb >> 24) & 0xFF) | ((nb >> 8) & 0xFF00)
    | ((nb << 8) & 0xFF0000) | ((nb << 24) & 0xFF000000);
}

int file_to_header(int argc, char **argv, header_t *h, S_t *s)
{
    FILE *file;
    char *str = NULL;
    size_t len = 0;
    ssize_t read;

    h->magic = magic_in_header(COREWAR_EXEC_MAGIC);
    file = fopen(argv[1], "r");
    read = getline(&str, &len, file);
    name_in_header(argc, argv, str, h);
    read = getline(&str, &len, file);
    comment_in_header(argc, argv, str, h);
    size_in_header(str, h, s);
    free(str);
    fclose(file);
    return 0;
}
