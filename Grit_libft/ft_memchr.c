/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeawdou <akeawdou@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 06:56:50 by akeawdou          #+#    #+#             */
/*   Updated: 2022/09/09 07:14:56 by akeawdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	a;

	p = (unsigned char *)s;
	a = (unsigned char)c;
	while (n != 0)
	{
		if (*p == a)
			return (p);
		p++;
		n--;
	}
	return (NULL);
}
