/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-robotfactory-arnaud.jouan
** File description:
** core_file.c
*/
#include "rf.h"
#include "op.h"
#include "my.h"

void static write_header(header_t *h, S_t *s)
{
    FILE *file = fopen(s->file_name, "wb");

    fwrite(h, sizeof(header_t), 1, file);
    fclose(file);
}

void static name_of_file(char **argv, header_t *h, S_t *s)
{
    int i = 0;

    if (argv[1][0] == '.' && argv[1][1] == '/')
        i = 2;
    if (i == 2) {
        s->file_name = malloc(my_strlen(argv[1]) * sizeof(char));
        for (; argv[1][i] != '.'; i++)
            s->file_name[i - 2] = argv[1][i];
    } else {
        s->file_name = malloc(my_strlen(argv[1]) + 2 * sizeof(char));
        for (; argv[1][i] != '.'; i++)
            s->file_name[i] = argv[1][i];
    }
    for (int i = 0; s->file_name[i] != '\0'; i++) {
        if (s->file_name[i] != 47 && s->file_name[i] < 97)
            s->file_name[i] = s->file_name[i] + 32;
    }
    s->file_name = my_strcat(s->file_name, ".cor");
}

void create_core_file(int argc, char **argv, header_t *h, S_t *s)
{
    name_of_file(argv, h, s);
    write_header(h, s);
    free(s->file_name);
}
