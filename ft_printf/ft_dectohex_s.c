/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:03:34 by drahwanj          #+#    #+#             */
/*   Updated: 2024/09/18 13:05:08 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dectohex_s(int fd, unsigned int num)
{
	int	counter;

	counter = 0;
	if (num >= 16)
	{
		counter += ft_dectohex_s(fd, num / 16);
		ft_dectohex_s(fd, num % 16);
		counter++;
	}
	else
	{
		if (num <= 9)
			counter += ft_putchar(fd, num + '0');
		else
		{
			counter += ft_putchar(fd, num - 10 + 'a');
		}
	}
	return (counter);
}
