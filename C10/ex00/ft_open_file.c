/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:02:58 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/21 16:11:47 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylib.h"

int	ft_open_file(char *filetitle)
{
	char	buff[2048];
	int		filedesc;
	int		bufflen;

	if ((filedesc = open(filetitle, O_RDONLY)) == -1)
		return (-1);
	while ((bufflen = read(filedesc, buff, 2048)) > 0)
		ft_putstr(buff);
	close(filedesc);
	if (bufflen)
		return (-1);
	return (0);
}
