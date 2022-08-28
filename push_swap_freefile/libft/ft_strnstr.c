/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:23:25 by wthanata          #+#    #+#             */
/*   Updated: 2022/03/12 20:06:52 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	int		j;

	if (haystack == NULL || needle == NULL)
		return (NULL);
	k = 0;
	if (*needle == '\0')
		return ((char *) haystack);
	while (*haystack && k < len)
	{
		j = 0;
		i = 0;
		while (haystack[j] == needle[j] && i + k < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *) haystack);
			j++;
			i++;
		}
		haystack++;
		k++;
	}
	return (0);
}
