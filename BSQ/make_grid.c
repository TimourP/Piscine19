/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:19:53 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/28 00:21:27 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void make_grid(int h, int w, char em, char nem, char square)
{
    int i;
    int j;

    i = -1;
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
            if (rand() % 10)
                write(1, &em, 1);
            else
                write(1, &nem, 1);
        }
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
    height = 5;
    width = 5;
    empty = '.';
    notempty = 'O';
    square = '#';
    make_grid(height, width, empty, notempty, square);
    return (0);
}