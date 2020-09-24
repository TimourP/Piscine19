/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewrite_userinput.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 14:49:53 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 15:27:56 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylib.h"

void ft_rewrite_userinput()
{
    char buff[2048];
    int bufflen;

    while ((bufflen = read(STDIN_FILENO, buff, 2048)) > 0)
		ft_putstr(buff);
}