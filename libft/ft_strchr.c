/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:56:41 by psaengha          #+#    #+#             */
/*   Updated: 2022/09/11 08:57:21 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			s = s + i;
			return ((char *)s);
		}
		i++;
	}
	if (c == 0)
	{
		s = s + len;
		return ((char *)s);
	}
	return (0);
}

/*int	main(void)
{
	char	s[] = "tripouille";
	int	test = 't' + 256;
	printf("%d\n", test);
	printf("%c\n", (char)test);
	printf("%s", ft_strchr(s, 't' + 256));
}*/
