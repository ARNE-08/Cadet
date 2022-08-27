/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:51:15 by psaengha          #+#    #+#             */
/*   Updated: 2022/08/27 09:51:16 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	const char		*ch1;
	const char		*ch2;

	c1 = '0';
	c2 = '0';
	ch1 = (const char *)s1;
	ch2 = (const char *)s2;
	while ((c1 == c2) && n > 0)
	{
		c1 = *ch1++;
		c2 = *ch2++;
		if (c1 == '\0')
			return (c1 - c2);
		n--;
	}
	return (c1 - c2);
}
