/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Infos
*/

int my_intlen(int a)
{
    int i = 0;

    while (a > 0) {
        a /= 10;
        i = i + 1;
    }
    return i;
}
