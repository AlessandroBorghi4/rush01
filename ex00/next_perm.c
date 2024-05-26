/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_perm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:48:32 by alborghi          #+#    #+#             */
/*   Updated: 2024/05/25 16:48:36 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

extern unsigned long long int g_iteration;

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	reverse(int arr[], int start, int end)
{
	while (start < end)
	{
		swap(&arr[start], &arr[end]);
		start++;
		end--;
	}
}

void	next_permutation(int arr[], int size)
{
	int	i;
	int	j;

	if (g_iteration % 100000000 == 0)
	{
		printf("current iterations: %llu\n", g_iteration);
	}
	g_iteration++;
	i = size - 2;
	while (i >= 0 && arr[i] >= arr[i + 1])
		i--;
	if (i >= 0)
	{
		j = size - 1;
		while (arr[j] <= arr[i])
			j--;
		swap(&arr[i], &arr[j]);
	}
	reverse(arr, i + 1, size - 1);
}
