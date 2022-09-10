/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:08:51 by psaengha          #+#    #+#             */
/*   Updated: 2022/09/10 16:21:50 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	int				len;
	unsigned char	*ch;

	i = 0;
	len = ft_strlen(s);
	ch = (unsigned char *)s;
	if (n == 0)
		return (0);
	while (ch[i] != '\0' && i < n)
	{
		if (ch[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	if (c == 0)
		return ((void *)s);
	return (0);
}
