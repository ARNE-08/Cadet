/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:20:24 by wthanata          #+#    #+#             */
/*   Updated: 2022/08/25 11:48:33 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_stack	*ft_create_elem(int data)
{
	t_stack	*elem;

	elem = (t_stack *)malloc(sizeof(t_stack));
	if (elem == NULL)
		return (NULL);
	elem->num = data;
	elem->next = NULL;
	return (elem);
}

void	ft_list_push_back(t_stack **begin_list, int data)
{
	t_stack	*lastelem;

	lastelem = *begin_list;
	if (lastelem != NULL)
	{
		while (lastelem->next)
			lastelem = lastelem->next;
		lastelem->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

void	ft_sort_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	tmp;

	a = 0;
	while (a < size)
	{
		b = a;
		while (b < size)
		{
			if (tab[a] >= tab[b])
			{
				tmp = tab[b];
				tab[b] = tab[a];
				tab[a] = tmp;
			}
			b++;
		}
		a++;
	}
}

void	put_list_order(int *tab, int size, t_stack *a)
{
	t_stack	*ptr;
	int		i;

	ptr = a;
	while (ptr)
	{
		i = 0;
		while (i < size)
		{
			if (ptr->num == tab[i])
			{
				ptr->order = i;
				break ;
			}
			i++;
		}
		ptr = ptr->next;
	}
}

t_stack	*create_list(int argc, char **argv, int j)
{
	t_stack	*a;
	int		*tab;
	int		i;

	tab = (int *)malloc(sizeof(int) * (argc - 1));
	a = NULL;
	i = 0;
	while (i < (argc - 1))
	{
		tab[i] = ft_atoi(argv[j + 1]);
		ft_list_push_back(&a, ft_atoi(argv[j + 1]));
		i++;
		j++;
	}
	ft_sort_tab(tab, (argc - 1));
	put_list_order(tab, (argc - 1), a);
	free(tab);
	return (a);
}
