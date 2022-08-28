/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:22:29 by psaengha          #+#    #+#             */
/*   Updated: 2022/08/27 16:22:29 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	int				j;

	i = 0;
	j = 0;
	if (len == 0 || needle[0] == '\0')
		return ((char *)haystack);
	while (i++ < len)
	{
		if (haystack[i] == needle[j++])
		{
			if (needle[j + 1] == '\0')
			{
				i -= j;
				haystack += i;
				return ((char *)haystack);
			}
		}
		else
		{
			i = i - j;
			j = 0;
		}
	}
	return (0);
}
