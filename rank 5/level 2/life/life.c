/* 
- dead cells need exactly 3 neighbours to be born
- alive cells survive with 2 or 3
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	**alloc_board(int w, int h)
{
	int i;
	int **b;

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

int	count_neighbours(int **board, int w, int h, int x, int y)
{
	int	dx;
	int	dy;
	int	count;
	int	nx;
	int	ny;

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
				if (nx >= 0 && nx < w && ny >= 0 && ny < h)
					count += board[ny][nx];
			}
			dx++;
		}
		dy++;
	}
	return (count);
}

void	free_board(int **board, int h)
{
	int	i;

	i = 0;
	while (i < h)
	{
		free(board[i]);
		i++;
	}
	free(board);
}

void	step_life(int **board, int w, int h)
{
	int	**next;
	int	x;
	int	y;
	int	n;

	next = alloc_board(w, h);
	if (!next)
		return ;
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			n = count_neighbours(board, w, h, x, y);
			if (board[y][x] == 1 && (n == 2 || n == 3))
				next[y][x] = 1;
			else if (board[y][x] == 0 && n == 3)
				next[y][x] = 1;
			else
				next[y][x] = 0;
			x++;
		}
		y++;
	}
	//copy updated next to the original board
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			board[y][x] = next[y][x];
			x++;
		}
		y++;
	}
	free_board(next, h);
}

void	print_board(int **board, int w, int h)
{
	int	x;
	int	y;

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

int	main(int argc, char **argv)
{
	int		width;
	int		height;
	int		iteration;
	int		**board;
	int		x;
	int		y;
	int		pen;
	char	c;

	if (argc != 4)
		return (1);
	width = atoi(argv[1]);
	height = atoi(argv[2]);
	iteration = atoi(argv[3]);

	board = alloc_board(width, height);
	if (!board)
		return (1);
	x = 0;
	y = 0;
	pen = 0;
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
		else if (c == 'd' && x < width - 1)
			x++;
		if (pen)
			board[y][x] = 1;
	}
	// while (iteration > 0)
	// {
	// 	step_life(board, width, height);
	// 	iteration--;
	// }
	print_board(board, width, height);
	free_board(board, height);
	return (0);

}