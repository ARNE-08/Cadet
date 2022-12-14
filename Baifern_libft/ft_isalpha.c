/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 22:23:28 by pleepago          #+#    #+#             */
/*   Updated: 2022/09/10 08:09:40 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int n)
{
	if (n >= 'a' && n <= 'z')
		return (1);
	else if (n >= 'A' && n <= 'Z')
		return (1);
	return (0);
}
