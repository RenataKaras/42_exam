#include "bsq.h"

int main(int argc, char **argv)
{
    t_map map;
    FILE *fp;

    if (argc == 1)
        fp = stdin;
    else if (argc == 2)
        fp = fopen(argv[1], "r");
    else
        return(fputs("Error: wrong number of arguments\n", stdout), 1);
    if (!read_map(fp, &map) || !validate_map(&map))
        return (invalid_map(), 1);
    solve_bsq(&map);
    print_map(&map);
    if (fp != stdin)
        fclose(fp);
    return (0);

}