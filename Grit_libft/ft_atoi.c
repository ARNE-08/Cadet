/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeawdou <akeawdou@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:30:05 by akeawdou          #+#    #+#             */
/*   Updated: 2022/09/11 07:47:37 by akeawdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	val;

	if (*nptr == '\0')
		return (0);
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == 32)
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	val = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		val = (val * 10) + (*nptr - 48);
		nptr++;
	}
	return (sign * val);
}
