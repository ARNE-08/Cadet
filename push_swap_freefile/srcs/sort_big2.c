/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:44:58 by wthanata          #+#    #+#             */
/*   Updated: 2022/08/27 18:16:58 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_stack	*to_last(t_stack **lst)
{
	t_stack	*ptr;

	ptr = *lst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

int	is_max_min(t_stack **a, t_stack **b, int mm)
{
	t_stack	*left;
	t_stack	*right;

	left = *a;
	right = *b;
	if (mm == 1)
	{
		while (right)
		{
			if (left->order < right->order)
				return (0);
			right = right->next;
		}
		return (1);
	}
	else
	{
		while (right)
		{
			if (left->order > right->order)
				return (0);
			right = right->next;
		}
		return (1);
	}
}

void	act_sort1(t_stack **a, t_stack **b)
{
	int		size;

	size = count_list(a);
	push_b(a, b);
	push_b(a, b);
	if ((*b)->order < (*b)->next->order)
		swap_b(b, 1);
	while (count_list(a) * 100 > size * 97)
	{
		if ((*a)->order > (*b)->order && (*a)->order < to_last(b)->order)
			push_b(a, b);
		else if ((*a)->order == 0 || (*a)->order == (size - 1)
			|| is_max_min(a, b, 1) || is_max_min(a, b, 0))
		{
			rot_high_top(b);
			push_b(a, b);
		}
		else
			rot_mid_top(a, b);
	}
}
