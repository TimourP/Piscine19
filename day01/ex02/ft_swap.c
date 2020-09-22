

void ft_swap(int *a, int *b)
{
    int transition;
    transition = *a;
    *a = *b;
    *b = transition;
}