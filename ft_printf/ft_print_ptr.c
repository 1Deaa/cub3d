/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:30:51 by drahwanj          #+#    #+#             */
/*   Updated: 2024/09/18 13:30:53 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(int fd, unsigned long long num)
{
	if (num >= 16)
	{
		ft_put_ptr(fd, num / 16);
		ft_put_ptr(fd, num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(fd, num + '0');
		else
			ft_putchar(fd, num - 10 + 'a');
	}
}

int	ft_print_ptr(int fd, unsigned long long ptr)
{
	int	counter;

	counter = 0;
	if (ptr == 0)
		counter += write(fd, "(nil)", 5);
	else
	{
		counter += write(fd, "0x", 2);
		ft_put_ptr(fd, ptr);
		counter += ft_ptr_len(ptr);
	}
	return (counter);
}
