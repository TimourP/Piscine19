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
    char memo[10000] = "Hello comment\n\n tu vas je me demade si ca fontionne je pense que ou\0iiiiiiiiiiiiiii";
    ft_print_memory(memo, ft_strlen(memo));
}