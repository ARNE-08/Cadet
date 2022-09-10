/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:34:00 by psaengha          #+#    #+#             */
/*   Updated: 2022/09/10 17:08:50 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*c;

	i = 0;
	if (!s)
		return (0);
	c = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!c)
		return (0);
	while (s[i] != '\0')
	{
		c[i] = (*f)(i, s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
