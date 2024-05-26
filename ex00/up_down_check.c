/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:12:48 by alborghi          #+#    #+#             */
/*   Updated: 2024/05/26 16:12:49 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0

int	up_row_check(int **mat, int size, int col, int *rule)
{
	int	row;
	int	seen;
	int	height;

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
			row = size;
		else
			row++;
	}
	if (seen != rule[col])
		return (FALSE);
	return (TRUE);
}

int	check_up(int **mat, int size, int *rule)
{
	int	col;

	col = 0;
	while (col < size)
	{
		if (!up_row_check(mat, size, col, rule))
			return (FALSE);
		col++;
	}
	return (TRUE);
}

int	down_row_check(int **mat, int size, int col, int *rule)
{
	int	row;
	int	seen;
	int	height;

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
			row = -1;
		else
			row--;
	}
	if (seen != rule[col])
		return (FALSE);
	return (TRUE);
}

int	check_down(int **mat, int size, int *rule)
{
	int	col;

	col = 0;
	while (col < size)
	{
		if (!down_row_check(mat, size, col, rule))
			return (FALSE);
		col++;
	}
	return (TRUE);
}
