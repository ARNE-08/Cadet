/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:06:18 by wthanata          #+#    #+#             */
/*   Updated: 2022/08/20 18:06:10 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	to_top(t_stack **push, t_stack **lst)
{
	t_stack	*ptr;
	t_stack	*tmp;

	tmp = *push;
	*push = (*push)->next;
	ptr = *lst;
	if (ptr != NULL)
	{
		tmp->next = ptr;
		*lst = tmp;
	}
	else
	{
		tmp->next = NULL;
		*lst = tmp;
	}
}

void	push_a(t_stack **a, t_stack **b)
{
	if (b == NULL)
		return ;
	to_top(b, a);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **a, t_stack **b)
{
	if (a == NULL)
		return ;
	to_top(a, b);
	write(1, "pb\n", 3);
}
