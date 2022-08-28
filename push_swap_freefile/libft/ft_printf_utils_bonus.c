/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:07:21 by wthanata          #+#    #+#             */
/*   Updated: 2022/04/30 18:12:27 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putcharret_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstrret_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	whileloop(int n, int fd)
{
	char	c;
	int		mod;
	int		count;
	int		div;
	int		i;

	count = n / 10;
	div = 1;
	i = 0;
	while (count != 0)
	{
		count = count / 10;
		div = div * 10;
	}
	while (div > 0)
	{
		mod = n % div;
		n = n / div;
		c = n + '0';
		write(fd, &c, 1);
		i++;
		n = mod;
		div = div / 10;
	}
	return (i);
}

int	ft_putnbrret_fd(int n, int fd, t_flags *set)
{
	int	ret;

	ret = 0;
	if (set->space == 1 && n >= 0)
		ret = ret + ft_putcharret_fd(' ', 1);
	if (set->plus == 1 && n >= 0)
		ret = ret + ft_putcharret_fd('+', 1);
	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		n = 147483648;
		ret = 2;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
		ret = 1;
	}
	ret = ret + whileloop(n, fd);
	return (ret);
}

int	ft_putudret_fd(unsigned int n, int fd)
{
	char			c;
	unsigned int	mod;
	unsigned int	count;
	unsigned int	div;
	int				i;

	count = n / 10;
	div = 1;
	i = 0;
	while (count != 0)
	{
		count = count / 10;
		div = div * 10;
	}
	while (div > 0)
	{
		mod = n % div;
		n = n / div;
		c = n + '0';
		write(fd, &c, 1);
		i++;
		n = mod;
		div = div / 10;
	}
	return (i);
}
