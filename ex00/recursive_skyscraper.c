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
int		is_legal(int **mat, int row, int size, int **rule);
int		check_up(int **mat, int size, int *rule);
int		check_down(int **mat, int size, int *rule);
int		check_left(int **mat, int rows, int size, int *rule);
int		check_right(int **mat, int rows, int size, int *rule);

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
					return (TRUE);
			}
			else if (goal_test(*mat, size, rule))
				return (TRUE);
		}
		next_permutation((*mat)[row], size);
		i++;
	}
	return (FALSE);
}
