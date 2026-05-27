#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_map
{
	int rows;
	int columns;
	char empty;
	char obstacle;
	char full;
	char **grid;
} t_map;

typedef struct s_best
{
	int size;
	int row;
	int col;
} t_best;

void error_message(void);
int main(int argc, char **argv);
bool read_map(FILE *fp, t_map *map);
bool parse_header(char *line, t_map *map);
bool validate_map(t_map *map);
bool valid_char(t_map *map, char c);
void solve_bsq(t_map *map);
void fill_square(t_map *map, t_best best);
int min(int a, int b, int c);
int **alloc_dp(t_map *map);
void free_dp(int **dp, int h);
void	print_map(t_map *map);

