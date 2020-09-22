#include <stdio.h>
#include <stdlib.h>

void     ft_putstr(char *str);
int     ft_strlen(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
void	ft_putnbr_base(int nbr, char *base);

int		main(void)
{
	int test = 2147483647;
	ft_putnbr_base(test, "01234");
	return 0;
}
