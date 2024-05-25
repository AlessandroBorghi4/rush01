/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:57:12 by alborghi          #+#    #+#             */
/*   Updated: 2024/05/25 16:57:16 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#define START 0
#define TRUE 1
#define FALSE 0

int	r_skyscraper(int **mat, int row, int size, int **rule);

int	init(char *s, int **rule)
{
	int	idx;
	int num;

	idx = 0;
	num = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] >= '1' && s[idx] <= '9')
		{
			num++;
		}
		else if (s[idx] != ' ')
		{
			return (FALSE);
		}
		idx++;
	}
	if (num % 4 != 0)
	{
		return (FALSE);
	}
	size = num / 4;
	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] != ' ' && (s[idx] < '1' || s[idx] > size + '0'))
		{
			return (FALSE);
		}
		idx++;
	}
	init_rule(rule, size, s);
	return (FALSE);
}

void	init_rule(int **rule, int size, char *s)
{
	int	row;
	int	col;

	row = 0;
	malloc_matrix(rule, 4, size);
	while (row < 4)
	{
		col = 0;
		while (col < size)
		{
			
			col++;
		}
		row++;
	}
}

void	malloc_matrix(int **mat, int rows, int cols)
{
	int	row;

	rule = (int **)malloc(sizeof(int *) * rows);
	while (row < rows)
	{
		mat[row] = (int *)malloc(sizeof(int) * cols);
		row++;
	}
}

void free_matrix(int **mat, int rows)
{
	int	row;

	while (row < rows)
	{
		free(mat[row]);
		row++;
	}
	free(mat);
}

void	print_mat(int **mat, int size)

int	main(int argc, char **argv)
{
	int	**rule;
	int	size;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	size = init(argv[1], rule);
	if (size == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	
	if (r_skyscraper(mat, START, size, rule))
	{
		print_mat(mat, size);
	}
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
