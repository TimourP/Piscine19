/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:22:28 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/26 16:02:06 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void print_units(char c, char d, char u, t_num **dict);
char *find_char_in_dict(t_num **dict, char c);

void print_result(t_num **dict, char *nbr)
{
    unsigned int count;
    unsigned int i;

    count = ft_strlen(nbr);
    i = 0;
    if (count % 3 == 1)
    {
        print_units('0', '0', nbr[i], dict);
        i++;
    }    
    else if (count % 3 == 2)
    {
        print_units('0', nbr[i], nbr[i + 1], dict);
        i += 2;
    }
    if (i != 0)
    {
        if (count > 3)
            write(1, " ", 1);
        write_suffix(count - i + 1, dict);
    }
    while (i < count)
    {
        print_units(nbr[i], nbr[i + 1], nbr[i + 2], dict);
        if (i != count - 3)
            write(1, " ", 1);
        if ((nbr[i] != '0' || nbr[i + 1] != '0' || nbr[i + 2] != '0'))
            write_suffix(count - i - 2, dict);
        i += 3;
    } 
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
    if ((d != '0' || u != '0') && c != '0')
        ft_putstr(" ");
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
        {
            ft_putstr(" ");
            ft_putstr(find_char_in_dict(dict, u));
        }   
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