/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:24:12 by psaengha          #+#    #+#             */
/*   Updated: 2022/09/11 09:03:17 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;
	int	l;

	len = ft_strlen(s);
	l = len - 1;
	if (!s)
		return (0);
	if (c == 0)
	{
		s = s + len;
		return ((char *)s);
	}
	while (l >= 0)
	{
		if (s[l] == (char)c)
		{
			s = s + l;
			return ((char *)s);
		}
		l--;
	}
	return (0);
}
