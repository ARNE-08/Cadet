/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:14:53 by wthanata          #+#    #+#             */
/*   Updated: 2022/03/12 22:14:20 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkchar(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	f;
	size_t	len;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	f = 0;
	while (s1[f] && checkchar(s1[f], set))
		f++;
	len = ft_strlen(s1);
	while (f < len && checkchar(s1[len - 1], set))
		len--;
	trim = malloc(sizeof(char) * (len - f + 1));
	if (trim == NULL)
		return (NULL);
	i = 0;
	while (f < len)
	{	
		trim[i] = s1[f];
		i++;
		f++;
	}
	trim[i] = '\0';
	return (trim);
}
