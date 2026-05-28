#include "bsq.h"

int main (int argc, char **argv)
{
	FILE *fp;
	t_map map;

	if (argc == 2)
	{
		fp = fopen(argv[1], "r");
		if (!fp)
			return(fputs("Error: invalid map\n", stdout), 1);
	}
	else if (argc == 1)
		fp = stdin;
	else
		return(fputs("Error: invalid map\n", stdout), 1);
	if (!read_map(fp, &map))
	{
		if (fp != stdin)
			fclose(fp);
		return(fputs("Error: invalid map\n", stdout), 1);
	}
		solve_bsq(&map);
	if (fp != stdin)
		fclose(fp);
	return (0);
}