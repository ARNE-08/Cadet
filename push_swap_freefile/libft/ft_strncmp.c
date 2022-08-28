/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:36:03 by wthanata          #+#    #+#             */
/*   Updated: 2022/03/12 20:05:27 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	ptr1 = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (ptr1[i] && ptr2[i] && ptr1[i] == ptr2[i] && i < n - 1)
		i++;
	return (ptr1[i] - ptr2[i]);
}
