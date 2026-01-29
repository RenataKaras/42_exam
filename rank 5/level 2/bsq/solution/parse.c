#include "bsq.h"

int valid_char(t_map *map, char c)
{
	if (c == map->empty || c == map->obstacle)
		return 1;
	return 0;
}

int validate_map(t_map *map)
{
	int i;
	int j;

	i = 0;

	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (!valid_char(map, map->grid[i][j]))
				return 0;
			j++;
		}
		if (map->grid[i][map->cols] != '\n')
			return (0);
		i++;
	}
	return 1;
}

int ft_atoi(char *string)
{
	int result = 0;
	int i = 0;

	while (string[i] >= '0' && string[i] <= '9')
	{
		result = result * 10 + (string[i] - '0');
		i++;
	}
	return result;
}

int parse_header(char *line, t_map *map)
{
	int i;
	i = 0;

	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (i == 0)
		return (0);
	map->rows = ft_atoi(line);
	if (map->rows <= 0)
		return(0);
	map->empty = line[i];
	map->obstacle = line[i + 1];
	map->full = line[i + 2];
	if (line[i + 3] != '\n')
		return 0;
	if (map->empty == map->obstacle || map->empty == map->full || map->obstacle == map->full)
		return (0);
	return (1);
}

int read_map(FILE *fp, t_map *map)
{
	char *line;
	size_t len;
	int i;
	ssize_t n;

	line = NULL;
	len = 0;
	if (getline(&line, &len, fp) == -1)
		return 0;
	if (!parse_header(line, map))
	{
		free(line);
		return 0;
	}
	free(line);
	map->grid = calloc(map->rows, sizeof(char *));
	if (!map->grid)
		return (0);
	i = 0;
	while (i < map->rows)
	{
		line = NULL;
		len = 0;
		n = getline(&line, &len, fp);
		if (n == -1)
		{
			free(line);
			return (0);
		}
		if (i == 0)
			map->cols = n - 1;
		if ((int)n - 1 != map->cols)
		{
			free(line);
			return 0;
		}
		map->grid[i] = line;
		i++;
	}
	return (1);

}
