#include "bsq.h"

static int min3(int a, int b, int c)
{
	int min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return min;
}

void solve_bsq(t_map *map)
{
	int **dp = calloc(map->rows, sizeof(int *));
	if (!dp)
		return ;
	int bi = 0, bj = 0, bsz = 0;
	for (int i = 0; i < map->rows; i++)
	{
		dp[i] = calloc(map->cols, sizeof(int));
		if (!dp[i])
		{
			while (i--)
				free(dp[i]);
			free(dp);
			return ;
		}
	}

	//calculating bi bj bsz
	for (int i = 0; i < map->rows; i++)
	{
		for (int j = 0; j < map->cols; j++)
		{
			if (map->grid[i][j] == map->obstacle)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = 1 + min3(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
			if (dp[i][j] > bsz)
			{
				bsz = dp[i][j];
				bi = i;
				bj = j;
			}
		}
	}

	//fill the full
	for (int i = bi; i > bi - bsz; i--)
	{
		for (int j = bj; j > bj - bsz; j--)
		{
			map->grid[i][j] = map->full;
		}
	}

	//print and free
	for (int i = 0; i < map->rows; i++)
	{
		fputs(map->grid[i], stdout);
		free(map->grid[i]);
	}
	free(map->grid);

	for (int i = 0; i < map->rows; i++)
		free(dp[i]);
	free(dp);
}