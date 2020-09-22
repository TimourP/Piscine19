#include <stdio.h>
#include <stdlib.h>

int			ft_atoi_base(char *str, char *base);

int main(void)
{
	char test[100] = "               -ponnvfi";
	char base[100] = "poneyvif";
	int test2 = ft_atoi_base(test, base);

	printf("%d ", test2);
	return (0);
}
