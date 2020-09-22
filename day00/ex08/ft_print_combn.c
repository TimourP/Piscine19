/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:35:56 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/09 12:35:58 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_list(int * arr, int n)
{
    char nub[10] = "0123456789";
    int i;
    i = -1;
    while(i++<n)
    {
        write(1, &nub[arr[i]], 1);
    }
    write(1, "\n",2);
}

void reinit_arr(int * arr, int count, int n)
{
    int i;
    i = -1;
    while(i++ < n - count)
    {
        count += 1;
        arr[count] = arr[count -1] + 1;
    }
}

void new_step(int * arr, int n)
{
    int count;
    int true;
    count = n;
    while(arr[count] == 9 - (n - count))
    {
        count --;
    }
    arr[count] = arr[count] + 1;
    if(count != n)
        reinit_arr(arr, count, n);
    print_list(arr, n);
}
void init_arr(int * arr, int size)
{
    int i;
    i = -1;
    while (i++ < size+1)
    {
        arr[i] = i;
    }
}

void ft_print_combn(int n)
{
    n = n-1;
    int main_array[n];
    init_arr(main_array, n);
    print_list(main_array, n);
    while(main_array[0] != 9-n)
    {
        new_step(main_array, n);
    }
}

int main()
{
    ft_print_combn(9);
    return 0;
}