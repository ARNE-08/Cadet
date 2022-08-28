/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:23:04 by wthanata          #+#    #+#             */
/*   Updated: 2022/08/25 11:48:13 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	exit_error(int error)
{
	write(2, "Error\n", 6);
	exit (error);
}

long long	ft_atoi_lld(const char *str)
{
	long long	sign;
	long long	num;

	sign = 1;
	num = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10;
		num = num + (*str - '0');
		str++;
	}
	return (sign * num);
}

int	check_argv(char *str)
{
	long long	num;
	int			i;

	i = 0;
	num = ft_atoi_lld(str);
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	if (num < -2147483648 || num > 2147483647)
		return (1);
	return (0);
}

void	do_check(char **arg, int i)
{
	int	j;

	while (arg[i])
	{
		if (check_argv(arg[i]))
			exit_error(1);
		j = i + 1;
		while (arg[j])
		{
			if (ft_atoi(arg[i]) == ft_atoi(arg[j]))
				exit_error(1);
			j++;
		}
		i++;
	}
}

t_stack	*arg_check(int argc, char **argv)
{
	char	**arg;
	int		j;
	int		k;

	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		do_check(arg, 0);
		j = -1;
	}
	else
	{
		arg = argv;
		do_check(arg, 1);
		j = 0;
	}
	k = 0;
	while (arg[k])
		k++;
	if (argc == 2)
		k++;
	return (create_list(k, arg, j));
}
