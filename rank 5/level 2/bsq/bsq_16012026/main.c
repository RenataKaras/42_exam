#include "bsq.h"

int main(int argc, char **argv)
{
	FILE *fp;
	t_map map;

	if (argc == 1)
		fp = stdin;
	if (argc == 2)
		fp = fopen(argv[1], "r");
	else
		return(error_message(), EXIT_FAILURE);
	if (!fp)
		return(fputs("Error: cannot open the file\n", stdout), EXIT_FAILURE);
	if (!read_map(fp, &map) || !validate_map(&map))
		return(error_message(), EXIT_FAILURE);
	solve_bsq(&map);
	print_map(&map);
	if (!fp == stdin)
		fclose(fp);
	return (EXIT_SUCCESS);
}