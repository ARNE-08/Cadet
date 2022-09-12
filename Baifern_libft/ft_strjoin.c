/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:07:44 by pleepago          #+#    #+#             */
/*   Updated: 2022/09/11 12:57:35 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			size;
	char			*p;
	unsigned int	n1;
	unsigned int	n2;

	if (!s1 || !s2)
		return (NULL);
	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	size = n1 + n2;
	p = (char *)malloc(sizeof(char) * size + 1);
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, n1);
	ft_memcpy(p + n1, s2, n2);
	p[size] = '\0';
	return (p);
}
