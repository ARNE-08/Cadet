/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeawdou <akeawdou@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:43:06 by akeawdou          #+#    #+#             */
/*   Updated: 2022/09/11 18:48:18 by akeawdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (NULL);
	if (len > (size_t)ft_strlen(s))
		len = (size_t)ft_strlen(s);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	*ptr = '\0';
	if (!s)
		return (ptr);
	if (!len)
		return (ptr);
	if (start > ft_strlen(s))
		return (ptr);
	ptr = ft_memcpy(ptr, s + start, len);
	ptr[len] = '\0';
	return (ptr);
}
