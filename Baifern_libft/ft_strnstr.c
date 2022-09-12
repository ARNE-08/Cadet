/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:19:23 by pleepago          #+#    #+#             */
/*   Updated: 2022/09/10 20:34:28 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((haystack == NULL || needle == NULL) && len == 0)
		return (NULL);
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && needle[j] != '\0' && i < len)
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			while (haystack[i + j] == needle[j] && (i + j) < len)
			{
				if (needle[j + 1] == '\0')
					return ((char *)haystack + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
