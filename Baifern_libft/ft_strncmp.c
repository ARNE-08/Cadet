/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:36:21 by pleepago          #+#    #+#             */
/*   Updated: 2022/09/10 20:11:11 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;	

	i = 0;
	j = 0;
	while ((s1[i] != '\0' || s2[j] != '\0') && n > 0)
	{
		if (s1[i] != s2[j])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[j]);
			break ;
		}
		i ++;
		j ++;
		n --;
	}
	return (0);
}
