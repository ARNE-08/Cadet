/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:31:50 by psaengha          #+#    #+#             */
/*   Updated: 2022/09/11 14:34:20 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!s || !str)
		return (0);
	while (s[i] != '\0')
	{
		if (i >= (unsigned long)start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

//2 8

/*int	main(void)
{
	char	s[] = "tripouille";
	printf("%s", ft_substr(s, 0, 42000));
}*/
