/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:27:46 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/23 14:58:29 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_print_first_line(unsigned long addr)
{
    printf("%lu\n", addr);
}

void *ft_print_memory(void *addr, unsigned int size)
{
    unsigned int i;

    i = 0;
    while (i < size)
    {
        ft_print_first_line((unsigned long)addr);
        i += 16;
    }
}