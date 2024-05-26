/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_source.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:38:37 by alborghi          #+#    #+#             */
/*   Updated: 2024/05/26 15:38:39 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define TRUE 1
#define FALSE 0

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
			if (!(idx == 0 || s[idx - 1] == ' '))
				return (FALSE);
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

int	init_all(char *s, int ***rule, int ***mat)
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
	malloc_matrix(mat, size, size);
	init_rule(rule, size, s);
	return (size);
}
