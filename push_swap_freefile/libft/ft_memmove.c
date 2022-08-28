/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:55:06 by wthanata          #+#    #+#             */
/*   Updated: 2022/03/13 13:21:05 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	if (dst == NULL || src == NULL)
		return (dst);
	i = 0;
	d = (char *) dst;
	s = (char *) src;
	if (s < d)
	{
		while (len >= ++i)
			d[len - i] = s[len - i];
	}
	else
	{
		while (len--)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
