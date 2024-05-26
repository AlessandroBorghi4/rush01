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
#include <stdio.h>

#define START 0
#define TRUE 1
#define FALSE 0

unsigned long long int g_iteration = 0;

int	r_skyscraper(int ***mat, int row, int size, int **rule);

void	malloc_matrix(int ***mat, int rows, int cols)
{
	int	row;

	row = 0;
	*mat = (int **)malloc(sizeof(int *) * rows);
	while (row < rows)
	{
		(*mat)[row] = (int *)malloc(sizeof(int) * cols);
		row++;
	}
}

void	free_matrix(int **mat, int rows)
{
	int	row;

	row = 0;
	while (row < rows)
	{
		free(mat[row]);
		row++;
	}
	free(mat);
}

void	print_matrix(int **mat, int rows, int cols)
{
	int	row;
	int	col;
	int	dig;

	row = 0;
	while (row < rows)
	{
		col = 0;
		while (col < cols)
		{
			if (col != 0)
			{
				write(1, " ", 1);
			}
			dig = mat[row][col] + '0';
			write(1, &dig, 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

void	init_rule(int ***rule, int size, char *s)
{
	int	row;
	int	col;
	int	idx;

	row = 0;
	idx = 0;
	malloc_matrix(rule, 4, size);
	while (row < 4)
	{
		col = 0;
		while (col < size)
		{
			if (s[idx] >= '1' && s[idx] <= size + '0')
			{
				(*rule)[row][col] = s[idx] - '0';
				col++;
			}
			idx++;
		}
		row++;
	}
}

int	init_lenght(char *s)
{
	int	idx;
	int	num;

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
	return (num / 4);
}

int	init_all(char *s, int ***rule)
{
	int	idx;
	int	size;

	size = init_lenght(s);
	idx = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] != ' ' && (s[idx] < '1' || s[idx] > size + '0'))
		{
			return (FALSE);
		}
		idx++;
	}
	init_rule(rule, size, s);
	return (size);
}

int	main(int argc, char **argv)
{
	int	**rule;
	int	size;
	int	**mat;

	mat = NULL;
	rule = NULL;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	size = init_all(argv[1], &rule);
	if (size == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	malloc_matrix(&mat, size, size);
	print_matrix(rule, 4, size);
	write(1, "\n", 1);
	print_matrix(mat, size, size);
	write(1, "\n", 1);
	if (r_skyscraper(&mat, START, size, rule))
	{
		print_matrix(mat, size, size);
	}
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	printf("total iterations: %llu\n", g_iteration);
	free_matrix(mat, size);
	free_matrix(rule, 4);
	return (0);
}
