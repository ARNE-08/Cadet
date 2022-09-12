/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeawdou <akeawdou@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:58:43 by akeawdou          #+#    #+#             */
/*   Updated: 2022/09/11 16:41:33 by akeawdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isin(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*ptr;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_isin(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_isin(s1[end - 1], set))
		end--;
	ptr = (char *)malloc((end - start + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
