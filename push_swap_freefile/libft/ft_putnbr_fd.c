/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:43:51 by wthanata          #+#    #+#             */
/*   Updated: 2022/03/11 20:37:12 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	whileloop(int n, int fd, int div)
{
	char	c;
	int		mod;

	while (div > 0)
	{
		mod = n % div;
		n = n / div;
		c = n + '0';
		write(fd, &c, 1);
		n = mod;
		div = div / 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	count;
	int	div;

	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	count = n / 10;
	div = 1;
	while (count != 0)
	{
		count = count / 10;
		div = div * 10;
	}
	whileloop(n, fd, div);
}
