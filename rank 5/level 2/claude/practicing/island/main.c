#include "island.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (Write(1, "Map Error\n",10), 1);

	int fd = open(argv[1], O_RDONLY);
	struct stat st;
	if (fd < 0)
		return (Write(1, "Map Error\n", 10), 1);
	if (fstat(fd, &st) < 0 || st.st_size == 0)
		return (close(fd), Write(1, "Map Error\n", 10), 1);
	char *buf = malloc(st.st_size + 1);
	if (!buf)
		return (close(fd), 1);
	read(fd, buf, st.st_size);
	buf[st.st_size] = '\0';
	close (fd);

	int rows, cols;
	if (!parse_map(buf, st.st_size, &rows, &cols))
	{
		free(buf);
		write(1, "Map Error\n", 10);
		return 1;
	}
	int best = 0;
	for (int i  = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			int size = dfs(buf, i, j, rows, cols);
			if (size > best)
				best = size;
		}
	write_int(best);
	write(1, "\n", 1);
	free(buf);
	return 0;
}