/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-robotfactory-arnaud.jouan
** File description:
** error_handling.c
*/
#include "rf.h"
#include "my.h"

static int check_header_name(int argc, char **argv, char *str, int *verif)
{
    int nb = 0;
    char *name = ".name ";

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\t' || *verif == 1)
            continue;
        nb = i;
        *verif = 1;
    }
    for (int j = 0; j < 6; j++) {
        if (name[j] != str[nb + j])
            return 84;
    }
    return 0;
}

static int check_header_comment(int argc, char **argv, char *str, int *verif)
{
    int nb = 0;
    char *comment = ".comment ";

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\t' || *verif == 0)
            continue;
        nb = i;
        *verif = 0;
    }
    for (int j = 0; j < 9; j++) {
        if (comment[j] != str[nb + j])
            return 84;
    }
    return 0;
}

int check_header(int argc, char **argv)
{
    FILE *file;
    char *str = NULL;
    size_t len = 0;
    ssize_t read;
    int verif = 0;

    file = fopen(argv[1], "r");
    read = getline(&str, &len, file);
    if (check_header_name(argc, argv, str, &verif) == 84)
        return 84;
    read = getline(&str, &len, file);
    if (check_header_comment(argc, argv, str, &verif) == 84)
        return 84;
    free(str);
    fclose(file);
    return 0;
}

int error(int argc, char **argv)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (argc != 2)
        return 84;
    file = fopen(argv[1], "r");
    if (file == NULL)
        return 84;
    read = getline(&line, &len, file);
    if (read == -1)
        return 84;
    free(line);
    fclose(file);
    return 0;
}
