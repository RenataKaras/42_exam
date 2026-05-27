#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>



int **alloc_board(int w, int h)
{
	int **b;
	int i;

	b = (int **)malloc(sizeof(int *) * h);
	if (!b)
		return (NULL);
	i = 0;
	while (i < h)
	{
		b[i] = (int *)calloc(w, sizeof(int));
		if (!b[i])
			return (NULL);
		i++;
	}
	return (b);
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
		putchar('\n');
		y++;
	}
}

void free_board(int **board, int h)
{
	int i;

	i = 0;
	while (i < h)
	{
		free (board[i]);
		i++;
	}
	free(board);
}

int count_neighbours(int **board, int w, int h, int x, int y)
{
	int dx;
	int dy;
	int count;
	int nx;
	int ny;

	count = 0;
	dy = -1;

	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			if (!(dx == 0 && dy == 0))
			{
				nx = dx + x;
				ny = dy + y;
				if (nx >= 0 && nx < w && ny >= 0 && ny < h)
					count += board[ny][nx];
			}
			dx++;
		}
		dy++;
	}
	return (count);
}

void	iteration(int **board, int w, int h)
{
	int **temp;
	int x;
	int y;
	int n;

	temp = alloc_board(w, h);
	if (!temp)
		return ;
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			n = count_neighbours(board, w, h, x, y);
			if (board[y][x] == 1 && (n == 2 || n == 3))
				temp[y][x] = 1;
			else if (board[y][x] == 0 && n == 3)
				temp [y][x] = 1;
			else
				temp[y][x] = 0;
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
			board[y][x] = temp[y][x];
			x++;
		}
		y++;
	}
	free_board(temp, h);
}

int main (int argc, char **argv)
{
	int width;
	int height;
	int iterations;
	int x;
	int y;
	char c;
	int **board;
	int pen;


	if (argc != 4)
		return (1);
	width = atoi(argv[1]);
	height = atoi(argv[2]);
	iterations = atoi(argv[3]);
	board = alloc_board(width, height);
	if (!board)
		return (1);
	x = 0;
	y = 0;
	pen = 0;
	while (read(0, &c, 1) > 0)
	{
		if (c == 'w' && y > 0)
			y--;
		else if (c == 's' && y < height - 1)
			y++;
		else if (c == 'a' && x > 0)
			x--;
		else if (c == 'd' && x < width - 1)
			x++;
		else if (c == 'x')
			pen = !pen;
		if (pen == 1)
			board[y][x] = 1;
	}
	while (iterations > 0)
	{
		iteration(board, width, height);//call the iteration
		iterations--;
	}
	print_board(board, width, height);
	free_board(board, height);
}