/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:26:56 by psaengha          #+#    #+#             */
/*   Updated: 2022/09/09 22:08:48 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;

	i = ft_strlen(dst);
	if (i >= dstsize)
		return (dstsize + ft_strlen(src));
	while (*src != '\0' && i < dstsize - 1)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (ft_strlen(src) + i);
}
