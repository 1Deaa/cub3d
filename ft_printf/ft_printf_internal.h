/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drahwanj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 01:16:20 by drahwanj          #+#    #+#             */
/*   Updated: 2025/06/21 01:16:20 by drahwanj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include "ft_printf.h"

int	ft_putchar(int fd, int c);
int	ft_choose(int fd, const char *s, va_list args, int index);
int	ft_putstr(int fd, char *str);
int	ft_putnbr(int fd, int n);
int	ft_putunsigned(int fd, unsigned int n);
int	ft_dectohex_c(int fd, unsigned int num);
int	ft_dectohex_s(int fd, unsigned int num);
int	ft_print_ptr(int fd, unsigned long long num);

#endif