#include "bsq.h"

int **alloc_dp(t_map *map)
{
	int i = 0;
	int **temp;
	temp = malloc(sizeof(int *) * map->rows);
	if (!temp)
		return (NULL);
	while (i < map->rows)
	{
		temp[i] = calloc(map->cols, sizeof(int));
		if (!temp[i])
			return (NULL);
		i++;
	}
	return temp;
}

void fill_square(t_map *map, t_square best)
{
	int i;
	int j;

	i = best.row;
	while (i > best.row - best.size)
	{
		j = best.col;
		while (j > best.col - best.size)
		{
			map->grid[i][j] = map->full;
			j--;
		}
		i--;
	}
}

void free_dp(int **dp, int h)
{
	int i = 0;
	while (i < h)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}

int min(int a, int b, int c)
{
	int min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

void solve_bsq(t_map *map)
{
	int **dp;
	t_square best;
	int i;
	int j;

	dp = alloc_dp(map);
	if (!dp)
		return ;
	best.size = 0;
	best.row = 0;
	best.col = 0;
	i = 0;

	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->grid[i][j] == map->obstacle)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i-1][j], dp[i][j-1]);
			if (dp[i][j] > best.size)
			{
				best.size = dp[i][j];
				best.row = i;
				best.col = j;
			}
			j++;
		}
		i++;
	}
	fill_square(map, best);
	free_dp(dp, map->rows);
}