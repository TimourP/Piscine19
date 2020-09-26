/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 04:06:06 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/26 06:07:52 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"
t_num **dict;
int init_dict(char *file_name);
int fill_dict(char *buffer, int length);
void add_word(char *buffer, int index, int count, int tot_word);
void printdict();

void write_numbers(char *file_name, char *number)
{
    int nbr;

    nbr = ft_atoi(number);
    if (!(init_dict(file_name)))
    {
        ft_putstr("Dict Error\n");
        return ;
    }
    if (nbr < 0)
    {
        ft_putstr("error\n");
        return ;
    }
    printdict();
    return ;
    write_billions(nbr / 1000000000, file_name);
    write_millions((nbr % 1000000000) / 1000000, file_name);
    write_thousands((nbr % 1000000) / 1000, file_name);
    write_units(nbr % 1000, file_name);
}

int init_dict(char *file_name)
{
    char	buff[16384];
	int		filedesc;
	int		bufflen;

    dict = malloc(sizeof(t_num) * 42);
    dict[42] = 0;
	if ((filedesc = open(file_name, O_RDONLY)) == -1)
		return (0);
	while ((bufflen = read(filedesc, buff, 16384)) > 0)
		fill_dict(buff, bufflen);
	close(filedesc);
	if (bufflen)
		return (0);
	return (1);
}

int fill_dict(char *buffer, int length)
{
    int i;
    int word_count;
    int inword;
    int tot_word;

    i = -1;
    tot_word = 0;
    word_count = 0;
    while (++i < length)
    {
        if (buffer[i] != '\n')
        {
            if (!inword)
                inword = 1;
            word_count++;
        }
        else if (inword)
        {
            add_word(buffer, i, word_count, tot_word);
            word_count = 0;
            inword = 0;
            tot_word++;
        }
    }
    if (inword)
        add_word(buffer, i, word_count, tot_word);
    return (1);
}

void add_word(char *buffer, int index, int count, int tot_word)
{
    long num;
    int j;
    int wordindex;
    char *currword;
    t_num *new;

    j = -1;
    num = 0;
    new = malloc(sizeof(t_num));
    while (buffer[index - count + ++j] >= '0' && buffer[index - count + j] <= '9')
        num = 10 * num + (buffer[index - count + j] - '0');
    j--;
    while (buffer[index - count + ++j] == ' ')
        ;
    if (buffer[index - count + j] == ':')
        j++;
    j--;
    while (buffer[index - count + ++j] == ' ')
        ;
    wordindex = 0;
    currword = malloc(sizeof(char) * (count - j + 1));
    j--;
    while (++j < count && ++wordindex)
        currword[wordindex - 1] = buffer[index - count + j];
    currword[wordindex] = 0;
    new->nbr = num;
    new->text_nbr = currword;
    dict[tot_word] = new;
}
