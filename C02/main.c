#include <stdio.h>

void *ft_print_memory(void *addr, unsigned int size);

int		ft_strlen(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int main(void)
{
    char memo[10000] = "Hello comme\0nt\n\n tu vas";
    ft_print_memory(memo, ft_strlen(memo) + 12);
}