/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-robotfactory-arnaud.jouan
** File description:
** main.c
*/
#include "rf.h"
#include "my.h"

static int check_header_name(int argc, char **argv, char *str, int i)
{
    char *name = ".name ";

    for (int j = 0; j < 6; j++) {
        if (name[j] != str[i + j])
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
    char *comment = ".comment ";
    int verif = 0;

    file = fopen(argv[1], "r");
    read = getline(&str, &len, file);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || verif == 1)
            continue;
        if (check_header_name(argc, argv, str, i) == 84)
            return 84;
        verif = 1;
    }
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

int tiret_h(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        my_printf("USAGE\n");
        my_printf("./asm file_name[.s]\n");
        my_printf("DESCRIPTION\n");
        my_printf("file_name file in assembly language to be converted into ");
        my_printf("file_name.cor, an executable in the Virtual Machine.\n");
        return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    S_t s;

    if (tiret_h(argc, argv) == 1)
        return 0;
    if (error(argc, argv) == 84 || check_header(argc, argv) == 84)
        return 84;
    return 0;
}
