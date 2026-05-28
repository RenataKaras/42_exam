#include "bsq.h"

static int	ft_atoi(char *str, int *dig)
{
	int res = 0;
	*dig = 0;
	while (str[*dig] >= '0' && str[*dig] <= '9')
		res = res * 10 + (str[(*dig)++] - '0');
	return res;
}

bool	read_map(FILE *fp, t_map *map)
{
	char *line = NULL;
	size_t len = 0;
	int dig = 0;
	ssize_t n;

	//header
	if (getline(&line, &len, fp) == -1)
		return (free(line), false);
	map->rows = ft_atoi(line, &dig);
	if (dig == 0 || map->rows <= 0 || line[dig + 3] != '\n')
		return (free(line), false);
	map->empty = line[dig];
	map->obstacle = line[dig + 1];
	map->full = line[dig + 2];
	if (map->empty == map->obstacle || map->empty == map->full || map->obstacle == map->full)
		return (free(line), false);
	free(line);

	//grid
	map->grid = calloc(map->rows, sizeof(char *));
	if (!map->grid)
		return false;
	for(int i = 0; i < map->rows; i++)
	{
		line = NULL;
		len = 0;
		n = getline(&line, &len, fp);
		if (n == -1)
			return (free(line), false);
		if (i == 0)
			map->cols = n-1;
		if ((int)n - 1 != map->cols)
			return(free(line), false);
		map->grid[i] = line;
	}

	//check valid char
	for (int i = 0; i < map->rows; i++)
	{
		for (int j = 0; j < map->cols; j++)
		{
			if (map->grid[i][j] != map->empty && map->grid[i][j] != map->obstacle)
			{
				for (int k = 0; k < map->rows; k++)
					free(map->grid[k]);
				free(map->grid);
				return false;
			}
		}
	}

	// printf("Rows: %d\n", map->rows);
	// printf("Empty: %c\n", map->empty);
	// printf("Obstacle: %c\n", map->obstacle);
	// printf("Full: %c\n", map->full);
	// for (int i = 0; i < map->rows; i++)
	// 	fputs(map->grid[i], stdout);


	return true;
}