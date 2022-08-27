/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:24:12 by psaengha          #+#    #+#             */
/*   Updated: 2022/08/27 11:24:15 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;
	int	l;

	len = ft_strlen(s);
	l = len - 1;
	if (c == len)
	{
		s = s + c;
		return ((char *)s);
	}
	while (s[l] != '\0')
	{
		if (s[l] == c)
		{
			s = s + l;
			return ((char *)s);
		}
		l--;
	}
	return (0);
}
