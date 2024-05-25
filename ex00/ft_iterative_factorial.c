/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:20:02 by alborghi          #+#    #+#             */
/*   Updated: 2024/05/21 16:20:04 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n;
	int	i;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	n = 1;
	i = 1;
	while (i <= nb)
	{
		if (i < 0)
			return (0);
		n *= i;
		i++;
	}
	return (n);
}
