/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeawdou <akeawdou@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:58:38 by akeawdou          #+#    #+#             */
/*   Updated: 2022/09/11 21:38:14 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	ft_reverse(char *str, int n)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = n - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

int		ft_abs(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

char	*ft_getz(char *ptr)
{
	ptr[0] = '0';
	ptr[1] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		isneg;

	ptr = (char *)malloc(12 * sizeof(char));
	if (!ptr)
		return (NULL);
	if (n == 0)
		return (ft_getz(ptr));
	isneg = 0;
	if (n < 0)
		isneg = 1;
	i = 0;
	while (n != 0)
	{
		ptr[i++] = ft_abs((n % 10)) + '0';
		n = n / 10;
	}
	if (isneg)
		ptr[i++] = '-';
	ptr[i] = '\0';
	ft_reverse(ptr, i);
	return (ptr);
}

int	main(void)
{
	printf("%s\n", ft_itoa(0));
	printf("%d", strcmp(ft_itoa(0), "0"));
}
