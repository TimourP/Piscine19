#include <unistd.h>


void ft_putnbr(int nb)
{
    char int_2_string[12] = "";
    char possint[10] = "0123456789";
    int count;
    count = 0;
    while (nb > 0)
    {
        int_2_string[11-count] = possint[nb%10];
        nb = nb / 10;
        count ++;
    }
    write(1, int_2_string, 12);
}
