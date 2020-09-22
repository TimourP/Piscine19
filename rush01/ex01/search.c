
#include <unistd.h>

int	g_foundsmth = 0;
int	g_grid[81] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int		can_put_nbr(int index, int nbr);
void	put_nbr_in_grid(int index, int nbr);
int		respect_borders(int *grid, int *borders);
void	print_solution(void);

int		search(int index, int *borders)
{
	int nbr;

	nbr = 1;
	if (index == 81)
	{
		if (respect_borders(g_grid, borders))
		{
			print_solution();
			g_foundsmth = 1;
		}
		return g_foundsmth;
	}
	while(nbr <= 9)
	{
		if (can_put_nbr(index, nbr))
		{
			put_nbr_in_grid(index, nbr);
			search(index + 1, borders);
			if (g_foundsmth)
				return g_foundsmth;
			put_nbr_in_grid(index, 0);
		}
		nbr++;
	}
	return (g_foundsmth);
}

int can_put_nbr(int index, int nbr)
{
	int x;
	int y;
	int i;

	x = index % 9;
	y = index / 9;
	i = -1;
	while (++i < 9)
	{
		if (g_grid[y * 9 + i] == nbr)
			return (0);
		if (g_grid[i * 9 + x] == nbr)
			return (0);
	}
	return (1);
}

void	put_nbr_in_grid(int index, int nbr)
{
	g_grid[index] = nbr;
}

void	print_solution()
{
	int x;
	int y;
	char c;

	y = -1;
	while (++y < 9)
	{
		x = -1;
		while (++x < 9)
		{
			c = '0' + g_grid[y * 9 + x];
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
}
