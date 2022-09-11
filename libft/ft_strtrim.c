/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 01:47:15 by psaengha          #+#    #+#             */
/*   Updated: 2022/09/11 14:35:12 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	haveset(char const *set, char s1)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	int		begin;
	int		stop;
	char	*str;

	i = 0;
	begin = 0;
	if (!s1 || !set)
		return (0);
	stop = ft_strlen(s1);
	while (haveset(set, s1[begin]) == 1)
		begin++;
	while (stop > begin && haveset(set, s1[stop - 1]) == 1)
		stop--;
	len = stop - begin;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	while (i < len)
		str[i++] = s1[begin++];
	str[i] = '\0';
	return (str);
}

/*static char *cut(char const *s1, char *dest, char const *set, int pos)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (s1[pos + 1] != 32 || s1[pos + 1] != '\0')
	{
		if (s1[pos] == set[j])
		{
			pos++;
			j++;
		}
		else
		{
			dest[k] = s1[pos];
			k++;
		}
		pos++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	k;
	int	count;
	char	*str;

	i = 0;
	j = 0;
	k = 0;
	count = 0;
	//printf("in");
	if (!s1)
		return (0);
	str = malloc(sizeof(char) * ft_strlen(s1));
	if (!str)
		return (0);
	while (s1[i])
	{
		while (s1[i] <= 32)
			i++;
		while (s1[i] > 32 && s1[i + 1] > 32)
		{
			i++;
			count++;
		}
		str = cut(s1, str, set, i - count);
		i++;
	}
	str[k] = '\0';
	return (str);
}

int	main(void)
{
	char	s1[] = "lorem ipsum dolor sit amet";
	char	set[] = "set";
	//printf("%s\n", s1);
	printf("%s", ft_strtrim(s1, set));
}

static size_t	count(char const *s1, char const *set, size_t pos)
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

/*char	*ft_strtrim(char const *s1, char const *set)
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
	size_t	i;
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
	return (str);
}*/
