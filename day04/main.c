#include <stdio.h>
#include <stdlib.h>

void     ft_putstr(char *str);
int     ft_strlen(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		ft_atoi_base(char *str, char *base);
void	ft_putnbr_base(int nbr, char *base);

int		main(void)
{
	char test[100] = "hello";
	int tt = ft_atoi_base(test, "hello");
	printf("%d\n", tt);
	return 0;
}
