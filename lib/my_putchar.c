/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** my_putchar.C
*/
#include "../mysh.h"

void my_putchar(char ch)
{
    write(1, &ch, 1);
}
