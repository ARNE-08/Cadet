/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:35:08 by wthanata          #+#    #+#             */
/*   Updated: 2022/08/27 17:32:42 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	count_list(t_stack **lst)
{
	t_stack	*ptr;
	int		i;

	ptr = *lst;
	i = 0;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

void	swap_a(t_stack **lst, int c)
{
	t_stack	*ptr;
	t_stack	*tmp;
	int		i;

	i = count_list(lst);
	if (i < 2)
		return ;
	ptr = *lst;
	*lst = (*lst)->next;
	if (i == 2)
	{
		(*lst)->next = ptr;
		ptr->next = NULL;
	}
	else
	{
		tmp = (*lst)->next;
		(*lst)->next = ptr;
		ptr->next = tmp;
	}
	if (c == 1)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack **lst, int c)
{
	t_stack	*ptr;
	t_stack	*tmp;
	int		i;

	i = count_list(lst);
	if (i < 2)
		return ;
	ptr = *lst;
	*lst = (*lst)->next;
	if (i == 2)
	{
		(*lst)->next = ptr;
		ptr->next = NULL;
	}
	else
	{
		tmp = (*lst)->next;
		(*lst)->next = ptr;
		ptr->next = tmp;
	}
	if (c == 1)
		write(1, "sb\n", 3);
}

void	swap_ab(t_stack **a, t_stack **b, int c)
{
	swap_a(a, c);
	swap_b(b, c);
	if (c == 2)
		write(1, "ss\n", 3);
}
