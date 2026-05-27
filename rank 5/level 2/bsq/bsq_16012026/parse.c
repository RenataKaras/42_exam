#include "bsq.h"

bool valid_char(t_map *map, char c)
{
	if (c == map->empty || c == map->obstacle)
		return true;
	return false;
}

bool validate_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (!valid_char(map, map->grid[i][j]))
				return (false);
			j++;
		}
		if (map->grid[i][map->columns] != '\n')
			return (false);
		i++;
	}
}

bool parse_header(char *line, t_map *map)
{
	int i = 0;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (i = 0)
		return false;
	map->rows = atoi(line);
	if (map->rows <= 0)
		return false;
	map->empty = line[i];
	map->obstacle = line[i + 1];
	map->full = line[i + 2];
	if (line[i+3] != '\n')
		return false;
	if (map->empty == map->obstacle || map->empty == map->full || map->obstacle == map->full)
		return false;
	return true;
}

bool read_map(FILE *fp, t_map *map)
{
	char *line;
	size_t len;
	ssize_t n;
	int i;

	line = NULL;
	len = 0;
	if(getline(&line, &len, fp) == -1)
		return false;
	if (!parse_header(line, map))
		return(free(line), false);
	free(line);
	map->grid = calloc(map->rows, sizeof(char *));
	if (map->grid)
		return false;
	i = 0;
	while (i < map->rows)
	{
		line = NULL;
		len = 0;
		n = getline(&line, &len, fp);
		if (n == -1)
			return(free(line), false);
		if (i == 0)
			map->columns = n - 1;
		if (map->columns != (int)n-1)
			return(free(line), false);
		map->grid[i] = line;
		i++;
	}
	return true;
}
