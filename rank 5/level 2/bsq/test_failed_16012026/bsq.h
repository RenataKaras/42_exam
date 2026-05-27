#ifndef BSQ_H
#define BSQ_H

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_map
{
    char **grid;
    char empty;
    char obstacle;
    char full;
    int rows;
    int cols;
} t_map;

typedef struct s_square
{
    int size;
    int rows;
    int cols;
} t_square;

void invalid_map(void);
int main(int argc, char **argv);
bool read_map(FILE *fp, t_map *map);
bool parse_header(char *line, t_map *map);
bool validate_map(t_map *map);
bool valid_char(t_map *map, char c);
int min(int a, int b, int c);
void free_dp(int **dp, int h);
int **alloc_dp(t_map *map);
void solve_bsq(t_map *map);
void print_map(t_map *map);



#endif
