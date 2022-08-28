/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:45:33 by wthanata          #+#    #+#             */
/*   Updated: 2022/08/17 20:11:18 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	charsep(char let, char c)
{
	if (let == c || let == '\0')
		return (1);
	return (0);
}

int	countword(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (charsep(str[i], c) == 0 && charsep(str[i + 1], c) == 1)
			count++;
		i++;
	}
	return (count);
}

int	strput(char *word, char *str, char c, int k)
{
	int	l;

	l = 0;
	while (!(charsep(str[l], c)))
	{
		word[l] = str[l];
		l++;
	}
	word[l] = '\0';
	k++;
	return (k);
}

void	*strcreate(char **split, char *str, char c, int i)
{
	int	j;
	int	k;

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (!(charsep(str[i + j], c)))
				j++;
			split[k] = malloc(sizeof(char) * (j + 1));
			if (split[k] == NULL)
			{
				while (k > 0)
					free(split[--k]);
				return (NULL);
			}
			k = strput(split[k], str + i, c, k);
			i = i + j;
		}
	}
	return ((void *)1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*str;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	str = (char *) s;
	j = countword(str, c);
	split = (char **)malloc(sizeof(char *) * (j + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	if (strcreate(split, str, c, i) == NULL)
	{
		free(split);
		return (NULL);
	}
	split[j] = 0;
	return (split);
}
