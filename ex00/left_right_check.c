/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:18:30 by alborghi          #+#    #+#             */
/*   Updated: 2024/05/26 16:18:31 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0

int	left_col_check(int **mat, int size, int row, int *rule)
{
	int	col;
	int	seen;
	int	height;

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
			col = size;
		else
			col++;
	}
	if (seen != rule[row])
		return (FALSE);
	return (TRUE);
}

int	check_left(int **mat, int rows, int size, int *rule)
{
	int	row;

	row = 0;
	while (row < rows)
	{
		if (!left_col_check(mat, size, row, rule))
			return (FALSE);
		row++;
	}
	return (TRUE);
}

int	right_col_check(int **mat, int size, int row, int *rule)
{
	int	col;
	int	seen;
	int	height;

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
			col = -1;
		else
			col--;
	}
	if (seen != rule[row])
		return (FALSE);
	return (TRUE);
}

int	check_right(int **mat, int rows, int size, int *rule)
{
	int	row;

	row = 0;
	while (row < rows)
	{
		if (!right_col_check(mat, size, row, rule))
			return (FALSE);
		row++;
	}
	return (TRUE);
}
