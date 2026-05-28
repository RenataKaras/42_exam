#ifndef BSQ_H
#define BSQ_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_map {
	char	**grid;
	int		cols;
	int		rows;
	char	empty;
	char	obstacle;
	char	full;
} t_map;

bool	read_map(FILE *fp, t_map *map);
void	solve_bsq(t_map *map);



#endif