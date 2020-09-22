#include <stdio.h>
#include <stdlib.h>

void     ft_putstr(char *str);
int     ft_strlen(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);

int		main(void)
{
	char test[100] = "-838k383";
	int num = ft_atoi(test);
	int num2 = atoi(test);
	if(num != num2)
		printf("%d, %d", num, num2);
	return 0;
}