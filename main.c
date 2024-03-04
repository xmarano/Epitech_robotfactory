/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-robotfactory-arnaud.jouan
** File description:
** main.c
*/
#include "rf.h"
#include "my.h"

void robot()
{
    FILE *file;
    char *text = "Hello bambino\n";

    file = fopen("./some-text.yolo", "w");
    fprintf(file, "%s", text);
    fclose(file);
    return;
}

int error(int argc, char **argv)
{
    if (argc != 2) {
        return 84;
    }
    return 0;
}

int h(int argc, char **argv)
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
    if (h(argc, argv) == 1)
        return 0;
    if (error(argc, argv) == 84)
        return 84;
    return 0;
}
