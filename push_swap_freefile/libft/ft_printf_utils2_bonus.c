/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:07:40 by wthanata          #+#    #+#             */
/*   Updated: 2022/04/30 18:12:10 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printout(unsigned int num, char *base, int fd)
{
	char	p;
	int		tab[1000];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (num > 0)
	{
		tab[i] = num % ft_strlen(base);
		num = num / ft_strlen(base);
		i++;
	}
	i--;
	while (i >= 0)
	{
		p = base[tab[i]];
		write(fd, &p, 1);
		j++;
		i--;
	}
	return (j);
}

int	ft_putnbrret_base_fd(unsigned int num, char *base, int fd, t_flags *set)
{
	char	p;
	int		i;

	i = 0;
	if (num == 0)
	{
		p = base[0];
		write(fd, &p, 1);
		i++;
		return (i);
	}
	if (set->hash == 1 && !ft_strncmp("0123456789abcdef", base, 16))
		i = ft_putstrret_fd("0x", 1);
	if (set->hash == 1 && !ft_strncmp("0123456789ABCDEF", base, 16))
		i = ft_putstrret_fd("0X", 1);
	i = i + printout(num, base, fd);
	return (i);
}

int	printout_lu(unsigned long num, char *base, int fd)
{
	char	p;
	int		tab[1000];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (num > 0)
	{
		tab[i] = num % ft_strlen(base);
		num = num / ft_strlen(base);
		i++;
	}
	i--;
	while (i >= 0)
	{
		p = base[tab[i]];
		write(fd, &p, 1);
		j++;
		i--;
	}
	return (j);
}

int	ft_putluret_base_fd(unsigned long num, char *base, int fd)
{
	char	p;
	int		i;

	i = 0;
	if (num == 0)
	{
		p = base[0];
		write(fd, &p, 1);
		i++;
		return (i);
	}
	i = printout_lu(num, base, fd);
	return (i);
}
