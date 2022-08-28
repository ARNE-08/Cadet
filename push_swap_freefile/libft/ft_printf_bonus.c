/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:07:04 by wthanata          #+#    #+#             */
/*   Updated: 2022/04/30 18:11:22 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_convers(va_list args, char format, t_flags *set)
{
	int	i;

	if (format == 'c')
		i = ft_putcharret_fd(va_arg(args, int), 1);
	else if (format == 's')
		i = ft_putstrret_fd(va_arg(args, char *), 1);
	else if (format == 'p')
	{
		i = ft_putstrret_fd("0x", 1);
		i = i + ft_putluret_base_fd((unsigned long)va_arg(args, void *),
				"0123456789abcdef", 1);
	}
	else if (format == 'd' || format == 'i')
		i = ft_putnbrret_fd(va_arg(args, int), 1, set);
	else if (format == 'u')
		i = ft_putudret_fd(va_arg(args, unsigned int), 1);
	else if (format == 'x')
		i = ft_putnbrret_base_fd(va_arg(args, unsigned int),
				"0123456789abcdef", 1, set);
	else if (format == 'X')
		i = ft_putnbrret_base_fd(va_arg(args, unsigned int),
				"0123456789ABCDEF", 1, set);
	else
		i = ft_putcharret_fd('%', 1);
	return (i);
}

int	ft_checkconv(char format)
{
	if (format == 'c' || format == 's' || format == 'p' || format == 'd'
		|| format == 'i' || format == 'u' || format == 'x'
		|| format == 'X' || format == '%')
		return (1);
	return (0);
}

void	ft_initialise_set(t_flags *set)
{
	set->minus = 0;
	set->zero = 0;
	set->dot = 0;
	set->hash = 0;
	set->space = 0;
	set->plus = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	set;
	int		count;

	ft_initialise_set(&set);
	va_start(args, format);
	count = ft_printf_case(format, &set, args);
	va_end(args);
	return (count);
}
