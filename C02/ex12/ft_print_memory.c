/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:27:46 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/23 11:39:43 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_first_line(char c)
{
    write(1, &c, 1);
}

void *ft_print_memory(void *addr, unsigned int size)
{
    unsigned int i;

    i = 0;
    while (i < size)
    {
        ft_print_first_line(addr + i);
        i += 16;
    }
}