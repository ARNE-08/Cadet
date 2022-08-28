/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:57:31 by wthanata          #+#    #+#             */
/*   Updated: 2022/03/12 18:21:44 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countint(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count = 2;
		n = 147483648;
	}
	if (n <= 0)
	{
		count++;
		n = n * (-1);
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	finddiv(int n)
{
	int			div;
	long int	num;

	div = 1;
	num = (long int) n;
	if (num < 0)
		num = num * (-1);
	num = num / 10;
	while (num > 0)
	{
		num = num / 10;
		div = div * 10;
	}
	return (div);
}

void	putstr(char *ret, int n, int div, int i)
{
	int	mod;

	if (n < 0)
	{
		ret[i] = '-';
		i++;
		n = n * (-1);
	}
	while (div > 0)
	{
		mod = n % div;
		n = n / div;
		ret[i] = n + '0';
		n = mod;
		div = div / 10;
		i++;
	}
	ret[i] = '\0';
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		div;
	int		i;

	ret = malloc(sizeof(char) * (countint(n) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	if (n == -2147483648)
	{
		ret[0] = '-';
		ret[1] = '2';
		i = 2;
		n = 147483648;
	}
	div = finddiv(n);
	putstr(ret, n, div, i);
	return (ret);
}
