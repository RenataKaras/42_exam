#ifndef	BSQ_H
# define BSQ_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

typedef struct	s_map
{
  int	  rows;
  int	  cols;
  char	empty;
  char	obstacle;
  char	full;
  char 	**grid;
}		t_map;

typedef struct	s_square
{
  int	size;
  int	row;
  int	col;
}		t_square;

int main(int argc, char **argv);
void error_invalid_map(void);
int read_map(FILE *fp, t_map *map);
int parse_header(char *line, t_map *map);
int validate_map(t_map *map);
int valid_char(t_map *map, char c);
void solve_bsq(t_map *map);
void free_dp(int **dp, int h);
void fill_square(t_map *map, t_square best);
int **alloc_dp(t_map *map);
void print_map(t_map *map);
int min(int a, int b, int c);






#endif
