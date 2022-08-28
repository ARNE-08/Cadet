/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:31:50 by wthanata          #+#    #+#             */
/*   Updated: 2022/03/12 20:10:06 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;
	int		i;

	if (dst == NULL || src == NULL)
		return (0);
	i = 0;
	a = ft_strlen(dst);
	b = ft_strlen(dst);
	if ((a >= dstsize) || (dstsize == 0))
		return (dstsize + ft_strlen(src));
	while ((a < dstsize - 1) && (src[i] != '\0'))
	{
		dst[a] = src[i];
		a++;
		i++;
	}
	dst[a] = '\0';
	return (ft_strlen(src) + b);
}
