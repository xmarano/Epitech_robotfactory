/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-robotfactory-arnaud.jouan
** File description:
** my.h
*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <signal.h>
#include <fcntl.h>
#ifndef MY_H
    #define MY_H
int my_intlen(int a);
int my_put_nbr(int nb);
int my_atoi(char *str);
char my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_put_nbr_recursive(int nb);
char *my_strdup(char const *src);
char **str_to_word_array(char *str);
int my_printf(const char *format, ...);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strncpy(char *dest, char const *src, int n);
#endif
