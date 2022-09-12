/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeawdou <akeawdou@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:14:16 by akeawdou          #+#    #+#             */
/*   Updated: 2022/09/11 13:15:26 by akeawdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		n;
	char	*ptr;

	n = ft_strlen(s);
	ptr = malloc(n * sizeof(char) + 1);
	if (ptr == NULL)
		return (ptr);
	while (n >= 0)
	{
		*(ptr + n) = *(s + n);
		n--;
	}
	return (ptr);
}
