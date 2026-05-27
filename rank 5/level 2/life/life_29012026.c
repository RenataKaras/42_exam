#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int **alloc_map(int h, int w)
{
	int i = 0;
	// int j;
	int **temp;
	temp = malloc(h * sizeof(int *));
	if (!temp)
		return NULL;
	while (i < h)
	{
		temp[i] = calloc(w, sizeof(int));
		if (!temp[i])
			return NULL;
		i++;
	}
	return (temp);
}

void print_board(int **b, int w, int h)
{
	int i;
	int j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (b[i][j] == 1)
				putchar('0');
			else
				putchar(' ');
			j++;
		}
		putchar ('\n');
		i++;
	}
}

void free_board(int **b, int h)
{
	int i = 0;
	while (i < h)
	{
		free(b[i]);
		i++;
	}
	free(b);
}

int main(int argc, char **argv)
{
	int width;
	int height;
	int iterations;
	int **map;
	int pen;
	char c;
	int x;
	int y;
	
	if (argc != 4)
		return 1;
	width = atoi(argv[1]);
	height = atoi(argv[2]);
	iterations = atoi(argv[3]);
	map = alloc_map(height, width);
	if (!map)
		return 1;
	pen = 0;
	x = 0;
	y = 0;
	while (read(0, &c, 1) > 0)
	{
		if (c == 'x')
			pen = !pen;
		else if (c == 'w' && y > 0)
			y--;
		else if (c == 'a' && x > 0)
			x--;
		else if (c == 's' && y < height - 1)
			y++;
		else if (c == 'd' && x < width - 1)
			x++;
		if (pen == 1)
			map[y][x] = 1;
	}

	//iterations

	print_board(map, width, height);
	free_board(map, height);

	return 0;
}