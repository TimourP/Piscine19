/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 04:32:57 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/26 04:52:35 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void write_billions(int nbr, char *file_name)
{
    printf("billions : %i\n", nbr);
    printf("%s\n", file_name);
}

void write_millions(int nbr, char *file_name)
{
    printf("millions : %i\n", nbr);
    printf("%s\n", file_name);
}

void write_thousands(int nbr, char *file_name)
{
    printf("thousands : %i\n", nbr);
    printf("%s\n", file_name);
}

void write_units(int nbr, char *file_name)
{
    printf("units : %i\n", nbr);
    printf("%s\n", file_name);
}