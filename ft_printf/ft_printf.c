/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:11:54 by drahwanj          #+#    #+#             */
/*   Updated: 2024/09/18 13:42:26 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(int fd, const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			count += ft_choose(fd, s, args, i + 1);
			i++;
		}
		else
			count += ft_putchar(fd, s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	int	num;
	int	num2;
	int x = 0;
	void *ptr = &x;

	num2 = 0;
	num = 0;

	num = ft_printf(" NULL %s NULL ", NULL);
	printf("\n");
	num2 = printf(" NULL %s NULL ", NULL);
	printf("\n");
	printf("Value of ft_printf: %d\n", num);
	printf("Value of og_printf: %d\n", num2);
}*/
