/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:36:56 by wthanata          #+#    #+#             */
/*   Updated: 2022/08/24 22:47:27 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sort_small_3(t_stack **a, t_stack **b)
{
	if (((*a)->order > (*a)->next->order) && ((*a)->next->order < \
		(*a)->next->next->order) && ((*a)->next->next->order > (*a)->order))
		swap_a(a, 1);
	else if (((*a)->order > (*a)->next->order) && ((*a)->next->order > \
		(*a)->next->next->order) && ((*a)->next->next->order < (*a)->order))
	{
		swap_a(a, 1);
		rev_rot_a(a, 1);
	}
	else if (((*a)->order > (*a)->next->order) && ((*a)->next->order < \
		(*a)->next->next->order) && ((*a)->next->next->order < (*a)->order))
		rot_a(a, 1);
	else if (((*a)->order < (*a)->next->order) && ((*a)->next->order > \
		(*a)->next->next->order) && ((*a)->next->next->order > (*a)->order))
	{
		swap_a(a, 1);
		rot_a(a, 1);
	}
	else if (((*a)->order < (*a)->next->order) && ((*a)->next->order > \
		(*a)->next->next->order) && ((*a)->next->next->order < (*a)->order))
		rev_rot_a(a, 1);
	(void) b;
}

void	sort_small_4(t_stack **a, t_stack **b)
{
	if ((*a)->next->order == 0)
		swap_a(a, 1);
	else if ((*a)->next->next->order == 0)
	{
		rev_rot_a(a, 1);
		rev_rot_a(a, 1);
	}
	else if ((*a)->next->next->next->order == 0)
		rev_rot_a(a, 1);
	push_b(a, b);
	sort_small(a, b);
	push_a(a, b);
}

void	sort_small_5(t_stack **a, t_stack **b)
{
	if ((*a)->next->order == 4)
		swap_a(a, 1);
	else if ((*a)->next->next->order == 4)
	{
		rot_a(a, 1);
		swap_a(a, 1);
	}
	else if ((*a)->next->next->next->order == 4)
	{
		rev_rot_a(a, 1);
		rev_rot_a(a, 1);
	}
	else if ((*a)->next->next->next->next->order == 4)
		rev_rot_a(a, 1);
	push_b(a, b);
	sort_small(a, b);
	push_a(a, b);
	rot_a(a, 1);
}

void	sort_small(t_stack **a, t_stack **b)
{
	if (count_list(a) == 2)
	{
		if ((*a)->order > (*a)->next->order)
			swap_a(a, 1);
		(void) b;
	}
	else if (count_list(a) == 3)
		sort_small_3(a, b);
	else if (count_list(a) == 4)
		sort_small_4(a, b);
	else if (count_list(a) == 5)
		sort_small_5(a, b);
}
