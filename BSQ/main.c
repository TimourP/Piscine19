/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:40:39 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/28 17:43:13 by mlefevre         ###   ########.fr       */
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
            find_square(argv[i]);
    }
    return (0);
}
