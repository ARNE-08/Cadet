/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:19:08 by wthanata          #+#    #+#             */
/*   Updated: 2022/03/12 20:11:40 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*tmp;

	ptr = (char *) s;
	tmp = 0;
	while (*ptr != '\0')
	{
		if (*ptr == (char) c)
			tmp = ptr;
		ptr++;
	}
	if ((char) c == '\0')
		return (ptr);
	if (tmp)
	{
		ptr = tmp;
		return (ptr);
	}
	return (0);
}
