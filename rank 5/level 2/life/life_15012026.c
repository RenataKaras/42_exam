#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int **alloc_board(int h, int w)
{
	int **b;
	int i;

	b = (int **)malloc(sizeof(int *) * h);
	if (!b)
		return NULL;
	i = 0;
	while (i < h)
	{
		b[i] = (int *)calloc(w, sizeof(int));
		i++;
	}
	return b;
}

void print_board(int **board, int w, int h)
{
	int x;
	int y;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (board[y][x] == 1)
				putchar('0');
			else
				putchar(' ');
			x++;
		}
		putchar ('\n');
		y++;
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

int count_neighbours(int **b, int w, int h, int x, int y)
{
	int dx;
	int dy;
	int nx;
	int ny;
	int count;

	count = 0;
	dy = -1;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			if (!(dx == 0 && dy == 0))
			{
				nx = x + dx;
				ny = y + dy;
				if (ny >= 0 && ny < h && nx >= 0 && nx < w)
					count += b[ny][nx];
			}
			dx++;
		}
		dy++;
	}
	return count;
}

void iteration(int **b, int w, int h)
{
	int **new;
	int x;
	int y;
	int n;

	new = alloc_board(h, w);
	if (!new)
		return ;
	y = 0;

	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			n = count_neighbours(b, w, h, x, y);
			if (b[y][x] == 1 && (n == 2 || n == 3))
				new[y][x] = 1;
			else if (b[y][x] == 0 && n == 3)
				new[y][x] = 1;
			else
				new[y][x] = 0;
			x++;
		}
		y++;
	}
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			b[y][x] = new[y][x];
			x++;
		}
		y++;
	}
	free_board(new, h);
}

int main(int argc, char **argv)
{
	int width;
	int height;
	int iter;
	int **board;
	int pen;
	char c;
	int x;
	int y;


	if (argc != 4)
		return (1);
	width = atoi(argv[1]);
	height = atoi(argv[2]);
	iter = atoi(argv[3]);

	board = alloc_board(height, width);
	if (!board)
		return (1);
	
	pen = 0;
	x = 0;
	y = 0;
	while (read(0, &c, 1) > 0)
	{
		if (c == 'x')
			pen = !pen;
		else if (c == 'w' && y > 0)
			y--;
		else if (c == 's' && y < height - 1)
			y++;
		else if (c == 'a' && x > 0)
			x--;
		else if (c == 'd' && x < width -1)
			x++;
		if (pen == 1)
			board[y][x] = 1;
	}

	while (iter > 0)
	{
		iteration(board, width, height);
		iter--;
	}
	print_board(board, width, height);
	free_board(board, height);
}
