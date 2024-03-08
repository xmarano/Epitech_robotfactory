/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-robotfactory-arnaud.jouan
** File description:
** core_file.c
*/
#include "rf.h"
#include "op.h"
#include "my.h"

void static write_header(header_t *h, S_t *s, char **argv)
{
    FILE *file;

    if (argv[2] != NULL) {
        my_printf("1 - (%s)\n", argv[2]);
        file = fopen(argv[2], "wb");
    } else if (argv[2] == NULL) {
        my_printf("2 - (%s)\n", s->file_name);
        file = fopen(s->file_name, "wb");
    }
    fwrite(h, sizeof(header_t), 1, file);
    fclose(file);
}

void static name_of_file(char **argv, header_t *h, S_t *s)
{
    int i = 0;
    int nb = 0;

    for (int i = 0; argv[1][i] != '\0'; i++) {
        if (argv[1][i] == '/')
            nb = i + 1;
    }
    s->file_name = malloc(nb + 4 * sizeof(char));
    for (; argv[1][nb] != '.'; nb++) {
        s->file_name[i] = argv[1][nb];
        i++;
    }
    for (int i = 0; s->file_name[i] != '\0'; i++) {
        if (s->file_name[i] >= 65 && s->file_name[i] <= 90)
            s->file_name[i] = s->file_name[i] + 32;
    }
    s->file_name = my_strcat(s->file_name, ".cor");
}

void create_core_file(int argc, char **argv, header_t *h, S_t *s)
{
    name_of_file(argv, h, s);
    write_header(h, s, argv);
    free(s->file_name);
}
