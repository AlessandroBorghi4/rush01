/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_legal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:44:07 by alborghi          #+#    #+#             */
/*   Updated: 2024/05/26 15:44:08 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0

int	check_right(int **mat, int rows, int size, int *rule);
int	check_left(int **mat, int rows, int size, int *rule);

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

int	repetition_check(int **mat, int row, int size)
{
	int	i;
	int	j;
	int	y;

	i = 0;
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

int	is_legal(int **mat, int row, int size, int **rule)
{
	int	i;

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
			return (FALSE);
	}
	if (!check_left(mat, row, size, rule[2])
		|| !check_right(mat, row, size, rule[3]))
	{
		return (FALSE);
	}
	if (!repetition_check(mat, row, size))
		return (FALSE);
	return (TRUE);
}
