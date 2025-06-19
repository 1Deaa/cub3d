/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:04:34 by drahwanj          #+#    #+#             */
/*   Updated: 2025/05/16 18:04:35 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_whitespace_and_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	return (sign);
}

static int	parse_digits_until_comma(const char *str, int *i,
	unsigned long *result)
{
	int	digit_found;

	digit_found = 0;
	while (ft_isdigit(str[*i]))
	{
		digit_found = 1;
		*result = (*result * 10) + (str[*i] - '0');
		(*i)++;
	}
	return (digit_found);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	i = 0;
	result = 0;
	if (!str)
		return (-1);
	sign = skip_whitespace_and_sign(str, &i);
	if (!parse_digits_until_comma(str, &i, &result))
		return (-1);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] != ',' && str[i] != '\0' && str[i] != '\n')
		return (-1);
	return ((int)(result * sign));
}
