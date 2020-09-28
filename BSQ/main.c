/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:40:39 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/28 15:26:02 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int main(int argc, char **argv)
{
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
}
