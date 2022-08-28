/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:39:33 by wthanata          #+#    #+#             */
/*   Updated: 2022/04/30 18:35:15 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_g(char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_g(char *s, int c)
{
	char	*ptr;

	if (s == NULL)
		return (NULL);
	ptr = s;
	while (*ptr != '\0')
	{
		if (*ptr == (char) c)
			return (ptr);
		ptr++;
	}
	if ((char) c == '\0')
		return (ptr);
	return (NULL);
}

char	*ft_strjoin_g(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		join[i] = s1[i];
	while (s2[j] != '\0')
		join[i++] = s2[j++];
	join[i] = '\0';
	free(s1);
	return (join);
}
