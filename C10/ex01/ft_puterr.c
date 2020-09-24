/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:56:56 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:07:22 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylib.h"

void	ft_puterr(char *progname, char *filename)
{
	int i;

	i = -1;
	while (progname[++i])
		write(2, &progname[i], 1);
	write(2, ": ", 2);
	i = -1;
	while (filename[++i])
		write(2, &filename[i], 1);
	write(2, ": No such file or directory\n", 28);
}
