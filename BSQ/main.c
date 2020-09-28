/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:40:39 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/28 10:50:28 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void write_bench(char *str, float t)
{
    fprintf(stderr, "%s: %f\n", str, t);
}

int main(int argc, char **argv)
{
    const float start = (float)clock() / CLOCKS_PER_SEC;////
    
    int i;

    i = 0;
    if (argc < 2)
        ft_putstr("Please enter file(s)'s name");
    else
    {
        while (++i < argc)
        {
            find_square(argv[i]);
        }
    }

    const float end = (float)clock() / CLOCKS_PER_SEC;////
    write_bench("main", end - start);////
}