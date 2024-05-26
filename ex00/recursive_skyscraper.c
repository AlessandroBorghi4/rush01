/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_skyscraper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:37:21 by alborghi          #+#    #+#             */
/*   Updated: 2024/05/25 16:37:23 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

int		ft_iterative_factorial(int nb);
void	next_permutation(int arr[], int size);

int	check_up(int **mat, int size, int *rule)
{
	int	row;
	int	col;
	int	seen;
	int	height;

	col = 0;
	while (col < size)
	{
		row = 0;
		seen = 0;
		height = 0;
		while (row < size)
		{
			if (mat[row][col] > height)
			{
				seen++;
				height = mat[row][col];
			}
			if (height == size)
			{
				row = size;
			}
			else
			{
				row++;
			}
		}
		if (seen != rule[col])
		{
			return (FALSE);
		}
		col++;
	}
	return (TRUE);
}

int	check_down(int **mat, int size, int *rule)
{
	int	row;
	int	col;
	int	seen;
	int	height;

	col = 0;
	while (col < size)
	{
		row = size - 1;
		seen = 0;
		height = 0;
		while (row >= 0)
		{
			if (mat[row][col] > height)
			{
				seen++;
				height = mat[row][col];
			}
			if (height == size)
			{
				row = -1;
			}
			else
			{
				row--;
			}
		}
		if (seen != rule[col])
		{
			return (FALSE);
		}
		col++;
	}
	return (TRUE);
}

int	check_left(int **mat, int rows, int size, int *rule)
{
	int	row;
	int	col;
	int	seen;
	int	height;

	row = 0;
	while (row < rows)
	{
		col = 0;
		seen = 0;
		height = 0;
		while (col < size)
		{
			if (mat[row][col] > height)
			{
				seen++;
				height = mat[row][col];
			}
			if (height == size)
			{
				col = size;
			}
			else
			{
				col++;
			}
		}
		if (seen != rule[row])
		{
			return (FALSE);
		}
		row++;
	}
	return (TRUE);
}

int	check_right(int **mat, int rows, int size, int *rule)
{
	int	row;
	int	col;
	int	seen;
	int	height;

	row = 0;
	while (row < rows)
	{
		col = size - 1;
		seen = 0;
		height = 0;
		while (col >= 0)
		{
			if (mat[row][col] > height)
			{
				seen++;
				height = mat[row][col];
			}
			if (height == size)
			{
				col = -1;
			}
			else
			{
				col--;
			}
		}
		if (seen != rule[row])
		{
			return (FALSE);
		}
		row++;
	}
	return (TRUE);
}

int	goal_test(int **mat, int size, int **rule)
{
	if (check_up(mat, size, rule[0])
		&& check_down(mat, size, rule[1])
		&& check_left(mat, size, size, rule[2])
		&& check_right(mat, size, size, rule[3]))
	{
		return (TRUE);
	}
	return (FALSE);
}

int	check_rows(int **mat, int row, int size, int *rule)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (rule[i] == 1)
		{
			if (mat[row][i] != size)
			{
				return (FALSE);
			}
		}
		else if (rule[i] == size)
		{
			if (mat[row][i] != 1)
			{
				return (FALSE);
			}
		}
		i++;
	}
	return (TRUE);
}

/*
FIXME: unused
*/
int	check_columns(int **mat, int row, int size, int **rule)
{
	if (rule[2][row] == 1 && mat[row][0] != size)
	{
		return (FALSE);
	}
	if (rule[2][row] == size && mat[row][0] != 1)
	{
		return (FALSE);
	}
	if (rule[3][row] == 1 && mat[row][size - 1] != size)
	{
		return (FALSE);
	}
	if (rule[3][row] == size && mat[row][size - 1] != 1)
	{
		return (FALSE);
	}
	return (TRUE);
}

int	is_legal(int **mat, int row, int size, int **rule)
{
	int	i;
	int	j;
	int	y;

	i = 0;
	if (row == 0)
	{
		if (!check_rows(mat, row, size, rule[0]))
		{
			return (FALSE);
		}
	}
	if (row == size - 1)
	{
		if (!check_rows(mat, row, size, rule[1]))
		{
			return (FALSE);
		}
	}
	if (!check_left(mat, row, size, rule[2])
		|| !check_right(mat, row, size, rule[3]))
	{
		return (FALSE);
	}
	while (i < size)
	{
		j = 0;
		while (j <= row - 1)
		{
			y = j + 1;
			while (y <= row)
			{
				if (mat[j][i] == mat[y][i])
					return (FALSE);
				y++;
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

void	init_row(int ***mat, int row, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		(*mat)[row][i] = i + 1;
		i++;
	}
}

int	r_skyscraper(int ***mat, int row, int size, int **rule)
{
	int	i;
	int	fact;

	i = 0;
	fact = ft_iterative_factorial(size);
	init_row(mat, row, size);
	while (i < fact)
	{
		if (is_legal((*mat), row, size, rule))
		{
			if (row != size - 1)
			{
				if (r_skyscraper(mat, row + 1, size, rule))
				{
					return (TRUE);
				}
			}
			else if (goal_test(*mat, size, rule))
			{
				return (TRUE);
			}
		}
		next_permutation((*mat)[row], size);
		i++;
	}
	return (FALSE);
}
