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

int	r_skyscraper(int ***mat, int row, int size, int **rule);
int	init_all(char *s, int ***rule, int ***mat);

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

void	print_matrix(int **mat, int rows, int cols, int **rule)
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
	free_matrix(mat, cols);
	free_matrix(rule, 4);
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
	size = init_all(argv[1], &rule, &mat);
	if (size <= 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (r_skyscraper(&mat, START, size, rule))
		print_matrix(mat, size, size, rule);
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
