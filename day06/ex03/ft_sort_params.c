/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:04:04 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/14 12:22:35 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_print_params(char *parname)
{
    int i;

    i = -1;
    while (parname[++i])
    {
        write(1, &parname[i], 1);
    }
    write(1, "\n", 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (s1[i] != '\0')
		return (s1[i]);
	else if (s2[i] != '\0')
		return (0 - s2[i]);
	return (0);
}

int     main(int argc, char **argv)
{
    int i;
    int j;
    int min;
    int last;

    i = 0;
    last = 0;
    while (++i < argc)
    {
        j = 0;
        min = 0;
        while(++j < argc)
        {
            if (ft_strcmp(argv[j], argv[min]) < 0 || min == 0)
            {
                if (ft_strcmp(argv[j], argv[last]) > 0 || last == 0)
                    min = j;
            }
        }
        ft_print_params(argv[min]);
        last = min;
    }
    return (0);
}