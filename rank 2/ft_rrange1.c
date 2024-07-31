int *ft_rrange (int start, int end)
{
	int i = 0;
	int size;
	int *array;
	if (start > end)
		ft_rrange(end, start);
	size = end - start + 1;
	array = malloc(size * sizeof(int));
	if (array)
	{
		while (i < size)
		{
			array[i] = end;
			end--;
			i++;
		}
	}
	return (array);
}