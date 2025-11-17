/*
** EPITECH PROJECT, 2024
** my_putnbr
** File description:
** rrrrrrr
*/

#include "../mysh.h"

int my_strnbr(int nbr)
{
    int r = 0;

    while (nbr > 0) {
        r++;
        nbr = nbr / 10;
    }
    return r;
}

int my_adapt_diviser(int nbr)
{
    int count = 0;
    int diviser = 1;

    nbr = my_strnbr(nbr);
    while (count < nbr -1) {
        diviser *= 10;
        count++;
    }
    return diviser;
}

int my_putnbr(int i)
{
    int diviser = my_adapt_diviser(i);
    int chiffre = i / diviser;

    if (i < 0) {
        my_putchar('-');
        return my_putnbr(i*(-1));
    }
    while (diviser != 0) {
        my_putchar(chiffre + '0');
        i = i % diviser;
        diviser /= 10;
        if (diviser != 0) {
        chiffre = i / diviser;
        }
    }
}
