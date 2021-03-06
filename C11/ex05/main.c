/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 08:00:50 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:08:01 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_op.h"

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	ft_solve_eq(argv[1], argv[2], argv[3]);
	return (0);
}
