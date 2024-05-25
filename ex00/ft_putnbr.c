/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:55:30 by alborghi          #+#    #+#             */
/*   Updated: 2024/05/15 10:55:34 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int nb)
{
	int		div;
	char	c;

	div = 1;
	while (nb / div >= 10)
	{
		div *= 10;
	}
	while (div > 0)
	{
		c = '0' + (nb / div);
		write(1, &c, 1);
		nb %= div;
		div /= 10;
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write(1, "2147483648", 10);
			return ;
		}
		nb = -nb;
	}
	print(nb);
}
