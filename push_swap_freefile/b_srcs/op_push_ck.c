/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_ck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:08:39 by wthanata          #+#    #+#             */
/*   Updated: 2022/08/27 17:32:12 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	push_a(t_stack **a, t_stack **b, int c)
{
	if (b == NULL)
		return ;
	to_top(b, a);
	if (c == 1)
		write(1, "pa\n", 3);
}

void	push_b(t_stack **a, t_stack **b, int c)
{
	if (a == NULL)
		return ;
	to_top(a, b);
	if (c == 1)
		write(1, "pb\n", 3);
}
