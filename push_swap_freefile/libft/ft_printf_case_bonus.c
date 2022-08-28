/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_case_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:54:59 by wthanata          #+#    #+#             */
/*   Updated: 2022/04/30 18:11:51 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	case_hash(const char *format, t_flags *set, va_list args, int *j)
{
	int	count;
	int	i;

	count = 0;
	*j += 2;
	i = *j;
	if (format[i] == 'x' || format[i] == 'X')
	{
		set->hash = 1;
		count = ft_convers(args, format[i], set);
	}
	set->hash = 0;
	return (count);
}

int	case_space(const char *format, t_flags *set, va_list args, int *j)
{
	int	count;
	int	i;

	count = 0;
	i = *j;
	while (format[i + 1] == ' ')
		i++;
	if (format[i + 1] == 'd' || format[i + 1] == 'i')
	{
		set->space = 1;
		count += ft_convers(args, format[++i], set);
	}
	set->space = 0;
	*j = i;
	return (count);
}

int	case_plus(const char *format, t_flags *set, va_list args, int *j)
{
	int	count;
	int	i;

	count = 0;
	i = *j;
	while (format[i + 1] == '+')
		i++;
	if (format[i + 1] == 'd' || format[i + 1] == 'i')
	{
		set->plus = 1;
		count += ft_convers(args, format[++i], set);
	}
	set->plus = 0;
	*j = i;
	return (count);
}

int	ft_printf_case(const char *format, t_flags *set, va_list args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
			count += ft_putcharret_fd(format[i], 1);
		else if (format[i] == '%' && ft_checkconv(format[i + 1]))
			count += ft_convers(args, format[++i], set);
		else if (format[i] == '%' && format[i + 1] == '#')
			count += case_hash(format, set, args, &i);
		else if (format[i] == '%' && format[i + 1] == ' ')
			count += case_space(format, set, args, &i);
		else if (format[i] == '%' && format[i + 1] == '+')
			count += case_plus(format, set, args, &i);
		i++;
	}
	return (count);
}
