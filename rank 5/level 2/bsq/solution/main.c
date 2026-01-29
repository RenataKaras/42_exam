#include "bsq.h"

int main(int argc, char **argv)
{
	FILE *fp;
	t_map map;

	if (argc == 1)
		fp = stdin;
	else if (argc == 2)
		fp = fopen(argv[1], "r");
	else
	{
		error_invalid_map();
		return (1);
	}
	if (!fp)
	{
		fprintf(stdout, "Error: %d\n", errno);
		return (1);
	}
	if (!read_map(fp, &map) || !validate_map(&map))
	{
		error_invalid_map();
		return(1);
	}
	solve_bsq(&map);
	print_map(&map);
	if(fp != stdin)
		fclose(fp);
	return(0);
}