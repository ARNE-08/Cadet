/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 10:19:28 by psaengha          #+#    #+#             */
/*   Updated: 2022/08/28 10:19:32 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char const	*ls;
	char		*ld;
	char		*d;
	char const	*s;

	d = (char *)dst;
	s = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		ls = s + (len - 1);
		ld = d + (len - 1);
		while (len--)
			*ld-- = *ls--;
	}
	return ((char *)dst);
}
/*
int	main(void)
{
	printf("%s", ft_memmove("Hello", "sandy", sizeof("sandy")));
}
int	main ()
{
	char dest[] = "oldstring";
	const char src[]  = "newstring";
	printf("Before memmove dest = %s, src = %s\n", dest, src);
	ft_memmove(dest, src, 9);
	printf("After memmove dest = %s, src = %s\n", dest, src);
	return(0);
}*/

/*void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;
	unsigned long	y;
	unsigned char	*ch1;
	unsigned char	*ch2;

	i = 0;
	y = 0;
	ch1 = (unsigned char *)dst;
	ch2 = (unsigned char *)src;
	while (i < len)
	{
		ch1[y] = ch2[i];
		i++;
	}
	dst = ch1;
	return (dst);
}*/
