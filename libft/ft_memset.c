/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:44:52 by psaengha          #+#    #+#             */
/*   Updated: 2022/08/26 22:44:53 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ch;
	unsigned long	i;

	i = 0;
	ch = (unsigned char *)b;
	while (i < len)
	{
		ch[i] = c;
		i++;
	}
	return (b = ch);
}
