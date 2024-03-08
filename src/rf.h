/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-robotfactory-arnaud.jouan
** File description:
** rf.h
*/
#include "my.h"
#include "op.h"
#ifndef RF_H
    #define RF_H

typedef struct S {
    char *file_name;
    char **arr;
} S_t;
int sti_function(S_t *s);
int add_function(S_t *s);
int error_file(int argc, char **argv);
int error_header(int argc, char **argv);
int error_body(int argc, char **argv, S_t *s);
int file_to_header(int argc, char **argv, header_t *h, S_t *s);
void create_core_file(int argc, char **argv, header_t *h, S_t *s);
#endif
