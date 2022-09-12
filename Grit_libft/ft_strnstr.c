/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeawdou <akeawdou@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 07:56:57 by akeawdou          #+#    #+#             */
/*   Updated: 2022/09/09 14:49:19 by akeawdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	while (len && *big)
	{
		i = 0;
		while (*(big + i) == *(little + i))
		{
			i++;
			if (*(little + i) == '\0' && i <= len)
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
