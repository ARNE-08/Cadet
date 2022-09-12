/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:05:30 by pleepago          #+#    #+#             */
/*   Updated: 2022/09/10 19:49:27 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*i;
	const unsigned char	*j;

	i = (const unsigned char *)s1;
	j = (const unsigned char *)s2;
	if (n)
	{
		while (n > 0)
		{
			if (*i != *j)
				return (*i - *j);
			i ++;
			j ++;
			n --;
		}
	}
	return (0);
}
