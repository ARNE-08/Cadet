/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:18:25 by pleepago          #+#    #+#             */
/*   Updated: 2022/09/10 20:01:54 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last_occurence;

	if (s[0] == 0 && c == 0)
		return ((char *)&s[0]);
	else if (s[0] == 0)
		return (NULL);
	i = 0;
	last_occurence = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			last_occurence = (char *)&s[i];
			i++;
	}
	if (c == 0)
		return (last_occurence = (char *)&s[i]);
	return (last_occurence);
}
