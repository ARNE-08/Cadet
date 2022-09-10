/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:28:24 by psaengha          #+#    #+#             */
/*   Updated: 2022/09/09 22:54:50 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *str, char c)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (str[y] != '\0')
	{
		if (str[y] != c)
			i++;
		y++;
	}
	return (i);
}

static char	*word(char const *s, int pos)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[pos] > 32)
	{
		len++;
		pos++;
	}
	pos = pos - len;
	str = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		str[i] = s[pos];
		i++;
		pos++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dst = (char **)malloc(sizeof(char *) * (count(s, c) + 1));
	while (s[i] != '\0')
	{
		while (s[i] == 9 || s[i] == 10 || s[i] == 32)
			i++;
		if (i == 0 || s[i - 1] <= 32)
		{
			dst[j] = word(s, i);
			j++;
		}
		i++;
	}
	dst[j] = 0;
	return (dst);
}
