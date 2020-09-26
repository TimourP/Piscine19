/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:22:28 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/26 13:31:47 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char *find_in_dict(t_num **dict, char *str);
void print_units(char c, char d, char u, t_num **dict);
char *find_char_in_dict(t_num **dict, char c);

void print_result(t_num **dict, char *nbr)
{
    unsigned int count;

    count = ft_strlen(nbr);
    print_units(nbr[0], nbr[1], nbr[2], dict);
}

void print_units(char c, char d, char u, t_num **dict)
{
    char arr[3] = {d, u, '\0'};

    if (c != '0')
    {
        ft_putstr(find_char_in_dict(dict, c));
        ft_putstr(" ");
        ft_putstr(find_in_dict(dict, "100"));
    }
    if (d < '2')
    {
        if (d < '1')
        {
            if (u != '0')
                ft_putstr(find_char_in_dict(dict, u));
        }
        else
            ft_putstr(find_in_dict(dict, arr));
    }
    else
    {
        arr[1] = '0';
        ft_putstr(find_in_dict(dict, arr));
        if (u != '0')
            ft_putstr(find_char_in_dict(dict, u));
    }
}

char *find_char_in_dict(t_num **dict, char c)
{
    int i;

    i = -1;
    while (dict[++i])
    {
        if (c == dict[i]->nbr[0] && !(dict[i]->nbr[1]))
            return (dict[i]->text_nbr);
    }
    return ("NULL");
}

char *find_in_dict(t_num **dict, char *str)
{
    int i;

    i = -1;
    while (dict[++i])
    {
        if (!ft_strcmp(str, dict[i]->nbr))
            return (dict[i]->text_nbr);
    }
    return ("NULL");
}