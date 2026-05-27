#include "bsq.h"

int **alloc_dp(t_map *map)
{
    int **temp;
    int i = 0;

    temp = malloc(map->rows * sizeof(int *));
    if (!temp)
        return NULL;
    while (i < map->rows)
    {
        temp[i] = calloc(map->cols, sizeof(int));
        i++;
    }
    return (temp);
}

int min(int a, int b, int c)
{
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
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

void fill_grid(t_square best, t_map *map)
{
    int i;
    int j;

    i = best.rows;
    while (i > best.rows - best.size)
    {
        j = best.cols;
        while (j > best.cols - best.size)
        {
            map->grid[i][j] = map->full;
            j--;
        }
        i--;
    }
}


void solve_bsq(t_map *map)
{
    int **dp;
    int i;
    int j;
    t_square best;

    dp = alloc_dp(map);
    if (!dp)
        return;
    best.size = 0;
    best.rows = 0;
    best.cols = 0;
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
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            if (dp[i][j] > best.size)
            {
                best.size = dp[i][j];
                best.rows = i;
                best.cols = j;
            }
            j++;
        }
        i++;
    }
    fill_grid(best, map);
    free_dp(dp, map->rows);
}