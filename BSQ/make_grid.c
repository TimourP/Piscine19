/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:19:53 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/28 13:04:44 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void make_grid(unsigned int h, unsigned int w, char em, char nem, char square)
{
    unsigned int i;
    unsigned int j;
    char *toprint;

    i = -1;
    toprint = malloc(sizeof(char) * w);
    ft_putnbr(h);
    write(1, &em, 1);
    write(1, &nem, 1);
    write(1, &square, 1);
    write(1, "\n", 1);
    while (++i < h)
    {
        j = -1;
        while (++j < w)
        {
            if (rand() % 1000)
                toprint[j] = em;
            else
                toprint[j] = nem;
        }
        write(1, toprint, w);
        write(1, "\n", 1);
    }
}

int main(void)
{
    int     height;
    int     width;
    char    empty;
    char    notempty;
    char    square;

    srand( time( NULL ) );
    height = 10000;
    width = 10000;
    empty = '.';
    notempty = 'O';
    square = '#';
    make_grid(height, width, empty, notempty, square);
    return (0);
}