/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 01:47:15 by psaengha          #+#    #+#             */
/*   Updated: 2022/08/28 01:47:16 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static size_t	count(char const *s1, char const *set, size_t pos)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (s1[i++] != '\0')
	{
		if (s1[i] == set[pos])
			count++;
	}
	return (count);
}

static */

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;
	char	*lw;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = 0;
	k = 0;
	str = malloc(sizeof(char) * ft_strlen(s1));
	while (s1[i] != '\0')
	{
		if (s1[i - 1] <= 32 && s1[i] > 32)
			lw = &((char *)s1)[i];
		i++;
	}
	i = 0;
	while (s1[i] != '\0')
	{
		while ((s1[i] >= 9 && s1[i] <= 13) || s1[i] == 32)
			i++;
		while (s1[i] > 32 && s1[i + 1] > 32)
		{
			while (set[k] != '\0')
			{
				if (s1[i] == set[k])
					i++;
				k++;
			}
			str[j] = s1[i];
			j++;
			i++;
		}
		//printf("why\n");
		str[j] = s1[i];
		k = 0;
		while ((*lw)++ != '\0')
		{
			if (s1[i] == set[k])
			{
				i++;
				k++;
			}
			str[j] = s1[i];
			j++;
			k++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
	/*size_t	i;
	size_t	j;
	size_t	k;
	size_t	c;
	char	*str;

	i = 0;
	j = 0;
	c = 0;
	if (!s1 || !set)
		return (0);
	while (set[i++] != '\0')
		c += count(s1, set, i);
	str = malloc(sizeof(char) * (ft_strlen(s1) - c + 1));
	if (!str)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		k = 0;
		while (set[k] != '\0')
		{
			if (s1[i] == set[k])
				i++;
			k++;
		}
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);*/
}

/*int	main(void)
{
	char	s1[] = "lorem ipsum dolor sit amet";
	char	set[] = "tel";
	printf("%s\n", s1);
	printf("%s", ft_strtrim(s1, set));
}*/
