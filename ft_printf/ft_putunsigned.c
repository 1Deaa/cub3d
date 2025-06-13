/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:28:59 by drahwanj          #+#    #+#             */
/*   Updated: 2024/09/16 18:25:45 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(int fd, unsigned int n)
{
	long unsigned int	nb;
	int					counter;

	counter = 0;
	nb = n;
	if (nb <= 9)
	{
		ft_putchar(fd, nb + '0');
		counter += 1;
	}
	if (nb > 9)
	{
		counter += ft_putunsigned(fd, nb / 10);
		ft_putunsigned(fd, nb % 10);
		counter += 1;
	}
	return (counter);
}
