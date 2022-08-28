/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:26:56 by psaengha          #+#    #+#             */
/*   Updated: 2022/08/27 15:26:58 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;

	i = 0;
	if (dstsize < 1)
		return (ft_strlen(src));
	while (src[i] != '\0')
	{
		dst[i + dstsize] = src[i];
		i++;
	}
	dst[i + dstsize] = '\0';
	return (ft_strlen(dst));
}

/*int	main(void)
{
	char	s1[] = "Hello";
	char	s2[] = "World!";
	printf("%lu", strlcat(s1, s2, 3));
}*/
