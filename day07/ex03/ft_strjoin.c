/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:38:39 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/16 13:59:02 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     tot_len(int size, char **strs, char *step)
{
    int i;
    int j;
    int count;

    i = -1;
    count = 0;
    while (++i < size)
    {
        j = -1;
        while (strs[i][j])
            count ++;
    }
    i = -1;
    while (step[++i])
        ;
    count += i * (size - 1);
    printf("%d\n", count);
    return (count);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    char *dest;


}