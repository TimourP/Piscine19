int	rowl(int *grid, int *borders)
{
	int i;
	int j;
	int max;
	int count;

	i = 17;
	while (++i < 27)
	{
		j = -1;
		count = 1;
		max = grid[(i - 18) * 9];
		while (++j < 8)
		{
			if (grid[(i - 18) * 9 + j + 1] > max)
			{
				max = grid[(i - 18) * 9 + j + 1];
				count++;
			}	
		}
		if (count != borders[i])
			return (0);
	}
	return (1);
}

int	rowr(int *grid, int *borders)
{
	int i;
	int j;
	int max;
	int count;

	i = 26;
	while (++i < 36)
	{
		j = -1;
		count = 1;
		max = grid[(i - 28) * 9 + 8];
		while (++j < 8)
		{
			if (grid[(i - 28) * 9 + 8 - 1 - j] > max)
			{
				max = grid[(i - 28) * 8 + 3 - 1 - j];
				count++;
			}	
		}
		if (count != borders[i])
			return (0);
	}
	return (1);
}

int colu(int *grid, int *borders)
{
	int i;
	int j;
	int max;
	int count;

	i = -1;
	while (++i < 9)
	{
		j = -1;
		count = 1;
		max = grid[i];
		while (++j < 8)
		{
			if (grid[((j + 1) * 9) + i] > max)
			{
				max = grid[((j + 1) * 9) + i];
				count++;
			}
		}
		if (count != borders[i])
			return (0);
	}
	return (1);
}

int cold(int *grid, int *borders)
{
	int i;
	int j;
	int max;
	int count;

	i = 8;
	while (++i < 18)
	{
		j = -1;
		count = 1;
		max = grid[63 + i];
		while (++j < 8)
		{
			if (grid[((7 - j) * 9) + (i - 9)] > max)
			{
				max = grid[((7 - j) * 9) + (i - 9)];
				count++;
			}
		}
		if (count != borders[i])
			return (0);
	}
	return (1);
}

int	respect_borders(int *grid, int *borders)
{
	if (rowl(grid, borders) && rowr(grid, borders) &&
	colu(grid, borders) && cold(grid, borders))
		return (1);
	return (0);
}
