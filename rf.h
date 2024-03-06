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
} S_t;
int error(int argc, char **argv);
int check_header(int argc, char **argv);
int file_to_header(int argc, char **argv, header_t *h, S_t *s);
void create_core_file(int argc, char **argv, header_t *h, S_t *s);
#endif
