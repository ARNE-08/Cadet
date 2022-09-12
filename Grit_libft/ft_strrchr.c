/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeawdou <akeawdou@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 07:31:36 by akeawdou          #+#    #+#             */
/*   Updated: 2022/09/11 07:19:32 by akeawdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	*a;

	p = (char *)s;
	a = NULL;
	while (*p != '\0')
	{
		if (*p == (char)c)
			a = p;
		p++;
	}
	if (c == '\0')
		return (p);
	if (a == NULL)
		return (NULL);
	return (a);
}
