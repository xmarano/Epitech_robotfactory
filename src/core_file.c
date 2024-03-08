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

    fwrite(&h->magic, sizeof(int), 1, file);
    fwrite(h->prog_name, sizeof(char), PROG_NAME_LENGTH, file);
    fwrite(&h->prog_size, sizeof(int), 1, file);
    fwrite(h->comment, sizeof(char), COMMENT_LENGTH, file);
    fclose(file);
}

void static name_of_file(char **argv, header_t *h, S_t *s)
{
    s->file_name = malloc(my_strlen(h->prog_name) + 4 * sizeof(char));
    s->file_name = my_strcat(s->file_name, h->prog_name);
    for (int i = 0; s->file_name[i] != '\0'; i++) {
        if (s->file_name[i] < 97)
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
