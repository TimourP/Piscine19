/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:40:39 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/28 17:06:21 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc < 2)
    {
        read_std_in();
        find_square("junk.txt");
    }
    else
    {
        while (++i < argc)
        {
            find_square(argv[i]);
        }
    }
}
