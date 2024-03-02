/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-robotfactory-arnaud.jouan
** File description:
** main.c
*/
#include "rf.h"
#include "my.h"

int main(void)
{
    FILE *file;
    char *text = "Hello bambino\n";

    file = fopen("./some-text.yolo", "w");
    fprintf(file, "%s", text);
    fclose(file);
    return 0;
}
