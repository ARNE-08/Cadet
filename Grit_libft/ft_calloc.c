/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeawdou <akeawdou@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:18:11 by akeawdou          #+#    #+#             */
/*   Updated: 2022/09/11 18:14:26 by akeawdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	b;
	void	*ptr;

	b = nmemb * size;
	if (b != 0 && b / nmemb != size)
		return (NULL);
	ptr = malloc(b);
	if (ptr != NULL)
		ft_memset(ptr, 0, b);
	return (ptr);
}
