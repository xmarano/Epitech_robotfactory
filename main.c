/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-robotfactory-arnaud.jouan
** File description:
** main.c
*/
#include "rf.h"
#include "op.h"
#include "my.h"

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
    header_t h;

    if (tiret_h(argc, argv) == 1)
        return 0;
    if (error(argc, argv) == 84 || check_header(argc, argv) == 84)
        return 84;
    file_to_header(argc, argv, &h);
    create_core_file(argc, argv, &h, &s);
    return 0;
}
