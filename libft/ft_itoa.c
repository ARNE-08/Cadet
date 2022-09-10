/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:13:51 by psaengha          #+#    #+#             */
/*   Updated: 2022/09/10 11:53:54 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

static int	divide(int len)
{
	int	digit;

	digit = 1;
	while (len > 1)
	{
		digit *= 10;
		len--;
	}
	return (digit);
}

static char	*makere(char *re, int n, int pos)
{
	int	len;
	int	uselen;

	len = numlen(n);
	uselen = len;
	if (re[0] == '-')
		uselen++;
	while (pos < uselen)
	{
		re[pos] = ((n / divide(len)) % 10) + 48;
		pos++;
		len--;
	}
	re[uselen] = '\0';
	return (re);
}

static char	*intmin(char *re, int pos)
{
	int	n;
	int	len;
	int	uselen;

	n = 214748364;
	len = numlen(n);
	uselen = len + 1;
	while (pos < uselen)
	{
		re[pos] = ((n / divide(len)) % 10) + 48;
		pos++;
		len--;
	}
	re[10] = '8';
	re[11] = '\0';
	return (re);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	int		uselen;
	char	*re;

	i = 0;
	len = numlen(n);
	uselen = len;
	re = malloc(sizeof(char) * len + 1);
	if (!re)
		return (0);
	if (n < 0)
	{
		re[i] = '-';
		n *= -1;
		i++;
		len--;
	}
	if (n == -2147483648)
	{
		re = intmin(re, i);
		return (re);
	}
	re = makere(re, n, i);
	return (re);
}

/*int	main(void) {
	printf("%s", ft_itoa(-2147483648));
	return (0);
}
len count "-" as len beacause when we turn it to
char [0] will be '-' and we still need more digit to fit the int
so in ito we minus the len when n < 0
in while loop divide len use to turn len in to 10, 100, etc
if we want to get two from 123 it will be 123 / 10 = 12
so we mod 10 for the 2*/
