/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:07:36 by wthanata          #+#    #+#             */
/*   Updated: 2022/03/12 18:13:25 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapi;
	char	*tmp;
	int		i;

	if (s == NULL)
		return (NULL);
	mapi = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (mapi == NULL)
		return (NULL);
	tmp = (char *) s;
	i = 0;
	while (tmp[i] != '\0')
	{
		mapi[i] = (*f)(i, tmp[i]);
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}
