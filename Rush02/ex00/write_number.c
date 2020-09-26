/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 04:06:06 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/26 17:21:50 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

t_num	**g_dict;
int		init_dict(char *file_name);
int		fill_dict(char *buffer, int length);
void	add_word(char *buffer, int index, int count, int tot_word);
int		count_lines(char *file_name);

void	write_numbers(char *file_name, char *number)
{
	const int init_value = init_dict(file_name);
	if (!init_value)
	{
		ft_putstr("Dict Error\n");
		return ;
	}
	else if (init_value == -1)
	{
		ft_putstr("Malloc Error\n");
		return ;
	}
	if (!check_num(number))
	{
		ft_putstr("Error\n");
		return ;
	}
	while (*number == '0')
		number++;
	if (!*number)
		write(1, find_in_dict(g_dict, "0"), ft_strlen(find_in_dict(g_dict, "0")));
	else
		print_result(g_dict, number);
	write(1, "\n", 1);
}

int		init_dict(char *file_name)
{
	char	buff[16384];
	int		filedesc;
	int		bufflen;
	int		num_of_lines;

	num_of_lines = count_lines(file_name);
	if (!(g_dict = malloc(sizeof(t_num *) * (num_of_lines + 1))))
		return (-1);
	g_dict[num_of_lines] = 0;
	if ((filedesc = open(file_name, O_RDONLY)) == -1)
		return (0);
	while ((bufflen = read(filedesc, buff, 16384)) > 0)
		fill_dict(buff, bufflen);
	if (close(filedesc)|| bufflen)
		return (0);
	return (1);
}

int		fill_dict(char *buffer, int length)
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

void	add_word(char *buffer, int i, int count, int tot_word)
{
	char	*num;
	int		j;
	int		wordindex;
	char	*currword;
	t_num	*new;

	j = -1;
	num = 0;
	new = malloc(sizeof(t_num));
	while (buffer[i - count + ++j] >= '0' && buffer[i - count + j] <= '9')
		;
	if (!(num = malloc(sizeof(char) * (j + 1))))
		return ;
	j = -1;
	while (buffer[i - count + ++j] >= '0' && buffer[i - count + j] <= '9')
		num[j] = buffer[i - count + j];
	num[j] = 0;
	j--;
	while (is_space(buffer[i - count + ++j]))
		;
	if (buffer[i - count + j] == ':')
		j++;
	j--;
	while (is_space(buffer[i - count + ++j]))
		;
	wordindex = 0;
	currword = malloc(sizeof(char) * (count - j + 1));
	j--;
	while (++j < count && ++wordindex)
		currword[wordindex - 1] = buffer[i - count + j];
	currword[wordindex] = 0;
	new->nbr = num;
	new->text_nbr = currword;
	g_dict[tot_word] = new;
}

int count_lines(char *file_name)
{
	char	buff;
	int		filedesc;
	int		bufflen;
	int		count;

	count = 0;
	if ((filedesc = open(file_name, O_RDONLY)) == -1)
		return (-1);
	while ((bufflen = read(filedesc, &buff, 1)) > 0)
		if (buff == '\n')
			count++;
	if (close(filedesc) == -1 || bufflen)
		return (-1);
	return (count);
}
