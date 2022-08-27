/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 01:18:21 by psaengha          #+#    #+#             */
/*   Updated: 2022/08/27 01:18:22 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;
	unsigned long	y;
	unsigned char	*ch1;
	unsigned char	*ch2;

	i = 0;
	y = 0;
	ch1 = (unsigned char *)dst;
	ch2 = (unsigned char *)src;
	while (i < len)
	{
		ch1[y] = ch2[i];
		i++;
	}
	dst = ch1;
	return (dst);
}
