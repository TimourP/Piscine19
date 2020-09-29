/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_std_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:43:59 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/28 19:49:54 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	read_std_in()
{
	const int fd = open("junk.txt", O_WRONLY | O_TRUNC | O_CREAT);
	char buf[2048];
	int bytes;

	if (fd == -1)
		return (ft_puterr("Cannot open junk.txt\n"));
	while((bytes = read(0, buf, 2048)) > 0)
		if (write(fd, buf, bytes) == -1)
			ft_puterr("Error while writing in junk.txt\n");	
	if (close(fd) == -1)
		return (ft_puterr("Cannot close junk.txt\n"));
	 if (bytes == -1)
	 	return (ft_puterr("Error while reading stdin\n"));
}
