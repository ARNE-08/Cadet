/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:46:17 by psaengha          #+#    #+#             */
/*   Updated: 2022/08/26 23:46:18 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	i;
	unsigned char	*ch1;
	unsigned char	*ch2;

	i = 0;
	ch1 = (unsigned char *)dst;
	ch2 = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		ch1[i] = ch2[i];
		i++;
	}
	return (dst);
}
