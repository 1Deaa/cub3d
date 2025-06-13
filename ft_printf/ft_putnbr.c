/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:28:51 by drahwanj          #+#    #+#             */
/*   Updated: 2024/09/16 18:10:41 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int fd, int n)
{
	long int	nb;
	int			i;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		ft_putchar(fd, '-');
		nb *= -1;
		i += 1;
	}
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(fd, nb + '0');
		i += 1;
	}
	if (nb > 9)
	{
		i += ft_putnbr(fd, nb / 10);
		ft_putnbr(fd, nb % 10);
		i += 1;
	}
	return (i);
}
