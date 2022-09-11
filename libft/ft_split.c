/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:28:24 by psaengha          #+#    #+#             */
/*   Updated: 2022/09/11 20:41:52 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_split(char c, char s)
{
	if (c == '\0' || c == s)
		return (1);
	return (0);
}

int	word_num(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_split(str[i + 1], c) && !is_split(str[i], c))
			count++;
		i++;
	}
	return (count);
}

void	put_str(char *dest, char *src, char c)
{
	int	i;

	i = 0;
	while (is_split(src[i], c) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	print(char **arr, char *str, char c)
{
	int	i;
	int	j;
	int	n_word;

	n_word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_split(str[i], c))
			i++;
		else
		{
			j = 0;
			while (is_split(str[i + j], c) == 0)
				j++;
			arr[n_word] = (char *)malloc(sizeof(char) * (j + 1));
			put_str(arr[n_word], str + i, c);
			i += j;
			n_word++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		word;
	char	*p;

	p = (char *)s;
	if (s == NULL)
		return (NULL);
	word = word_num(p, c);
	arr = (char **)malloc(sizeof(char *) * (word + 1));
	if (!arr)
		return (NULL);
	arr[word] = 0;
	print(arr, p, c);
	return (arr);
}

/*static int	count(char const *str, char c)
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

static char	*word(char const *s, int pos, char sep)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[pos] > 32  && s[pos] != sep)
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
	if (!s)
		return (0);
	dst = (char **)malloc(sizeof(char *) * (count(s, c) + 1));
	if (!dst)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == 9 || s[i] == 10 || s[i] == 32)
			i++;
		if (i == 0 || (s[i - 1] == c && s[i] != c))
		{
			dst[j] = word(s, i, c);
			j++;
		}
		i++;
	}
	dst[j] = 0;
	return (dst);
}

int	main(void)
{
	char	s[] = "    split  ||this|for|||me||||||";
	char	sp = ' ';
	char	**test = ft_split(s, sp);
	int		i = 0;
	while (test[i])
	{
		printf("%s\n", test[i]);
		//printf("loop");
		i++;
	}
}*/

/*4 8 10*/
