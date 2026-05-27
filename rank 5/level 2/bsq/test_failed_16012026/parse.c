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
        while (j < map->cols)
        {
            if (!valid_char(map, map->grid[i][j]))
                return false;
        j++;
        }
        if (map->grid[i][map->cols] != '\n')
            return false;
        i++;
    }
    return true;
}

bool parse_header(char *line, t_map *map)
{
    int i = 0;
    while (line[i] >= '0' && line[i] <= '9')
        i++;
    if (i == 0)
        return false;
    map->rows = line[0];
    if (map->rows <= 0)
        return false;
    map->empty = line[i];
    map->obstacle = line[i + 1];
    map->full = line[i + 2];
    if (line[i + 3] != '\n')
        return false;
    if (map->empty == map->obstacle || map->empty == map->full || map->obstacle == map->full)
        return false;
    return true;
}

bool read_map(FILE *fp, t_map *map)
{
    char *line;
    size_t len;
    int i;
    ssize_t n;

    line = NULL;
    len = 0;
    if (getline(&line, &len, fp) == -1)
        return (free(line), false);
    if (!parse_header(line, map))
        return (free(line),false);
    free(line);
    map->grid = calloc(map->rows, sizeof(char *));
    if (!map->grid)
        return NULL;
    i = 0;
    while (i < map->rows)
    {
        len = 0;
        line = NULL;
        n = getline(&line, &len, fp);
        if (n == -1)
            return (free(line), false);
        if (i == 0)
            map->cols = n - 1;
        if ((int)n - 1 != map->cols)
        {
            free(line);
            return (false);
        }
        map->grid[i] = line;
        // printf("in here\n");
        i++;
    }
    // printf("Empty: %c\n", map->empty);
    // printf("Obstacle: %c\n", map->obstacle);
    // printf("Full: %c\n", map->full);
    // printf("Rows: %d\n", map->rows);
    // printf("Columns: %d\n", map->cols);
    // i = 0;
    // int j;
    // while (i < map->rows)
    // {
    //     j = 0;
    //     while (j < map->cols)
    //     {
    //         printf("%c\n", map->grid[i][j]);
    //         j++;
    //     }
    //     // fputs(map->grid[i], stdout);
    //     i++;
    // }
    // free(line);
    return true;
}