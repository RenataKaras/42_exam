#include "bsq.h"

void print_map(t_map *map)
{
	int i;
	// int j;

	i = 0;
	while (i < map->rows)
	{
		fputs(map->grid[i], stdout);
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}
