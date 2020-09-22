/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:26:04 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/19 17:02:05 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylib.h"

int main(int argc, char **argv)
{
    if (argc == 1)
        ft_puterr("File name missing.");
    else if (argc != 2)
        ft_puterr("Too many arguments.");
    else if (ft_open_file(argv[1]) == -1)
        ft_puterr("Cannot read file.");
    return (0);
}