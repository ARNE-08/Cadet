/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 06:50:48 by pleepago          #+#    #+#             */
/*   Updated: 2022/09/11 12:58:52 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	lens;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	lens = ft_strlen(s);
	result = (char *)malloc((lens + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < lens)
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
