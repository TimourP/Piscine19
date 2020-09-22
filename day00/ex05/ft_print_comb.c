#include <unistd.h>


void print_list(int * arr)
{
    char nub[10] = "0123456789";
    int i;
    i = -1;
    while(i++<3)
    {
        write(1, &nub[arr[i]], 1);
    }
    if (arr[0] != 7)
        write(1, ", ",2);
}

void new_step(int * arr)
{
    if (arr[2] < 9)
        arr[2] ++;
    else if(arr[1] < 8)
    {
        arr[1] ++;
        arr[2] = arr[1] + 1;
    }
    else if(arr[0] < 7)
    {
        arr[0] ++;
        arr[1] = arr[0] + 1;
        arr[2] = arr[1] + 1;
    }
    print_list(arr);
}

void ft_print_comb()
{
    int main_array[3] = {0, 0, 0};
    int i;
    i = -1;
    while(main_array[0]!=7)
    {
        new_step(main_array);
    }
}