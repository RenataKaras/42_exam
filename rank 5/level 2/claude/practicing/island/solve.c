#include "island.h"

int	dfs(char *buf, int i, int j, int rows, int cols)
{
	if (i < 0 || i >= rows || j < 0 || j >= cols)
		return 0;
	int pos = i * (cols + 1) + j;
	if (buf[pos] != 'X')
		return 0;
	buf[pos] = '.';
	return 1
		+ dfs(buf, i - 1, j, rows, cols)
		+ dfs(buf, i + 1, j, rows, cols)
		+ dfs(buf, i, j - 1, rows, cols)
		+ dfs(buf, i, j + 1, rows, cols);
}

void write_int(int best)
{
	if (best >= 10)
		write_int(best / 10);
	char c = '0' + (best % 10);
	write (1, &c, 1);
}