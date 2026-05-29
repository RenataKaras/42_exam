#include "island.h"

bool parse_map(char *buf, int size, int *rows, int *cols)
{
	int c = 0;

	while (c < size && buf[c] != '\n')
		c++;
	if (c == 0 || c == size)
		return false;
	*cols = c;
	int row_size = c + 1;
	if (size % row_size != 0)
		return false;
	*rows = size / row_size;
	for (int i = 0; i < size; i++)
	{
		if (i + 1 % row_size == 0)
			if (buf[i] != '\n')
				return false;
		else if (buf[i] != '.' && buf[i] != 'X')
			return false;
	}
	return true;
}