

void ft_sort_int_tab(int * tab, int size)
{
    int i;
    i = -1;
    while (i++ < size - 1)
    {
        int min;
        int j;
        int transit;
        j = -1;
        while (j++ < size - i - 1)
        {
            if (tab[j+i] < min || j == 0)
                min = tab[j+i];
        }
        tab[j+i] = tab[i];
        tab[i] = min;
    }
}