/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:39:00 by wthanata          #+#    #+#             */
/*   Updated: 2022/08/27 14:41:56 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	count_move(t_stack **right, int index, int up_down)
{
	if (up_down == 0)
		return (index);
	else
		return (count_list(right) - index);
}

void	rot_high_top(t_stack **right)
{
	t_stack	*ptr;
	int		high;
	int		index;
	int		i;

	high = (*right)->order;
	i = 0;
	index = 0;
	ptr = *right;
	while (ptr)
	{
		if (high < ptr->order)
		{
			high = ptr->order;
			index = i;
		}
		ptr = ptr->next;
		i++;
	}
	if (count_move(right, index, 0) <= count_move(right, index, 1))
		while ((*right)->order != high)
			rot_b(right, 1);
	else if (count_move(right, index, 0) > count_move(right, index, 1))
		while ((*right)->order != high)
			rev_rot_b(right, 1);
}

void	act_mid(t_stack **right, int index)
{
	int	comp;

	comp = count_list(right) - index;
	if (count_move(right, index, 0) <= count_move(right, index, 1))
		while (index--)
			rot_b(right, 1);
	else if (count_move(right, index, 0) > count_move(right, index, 1))
		while (comp--)
			rev_rot_b(right, 1);
}

void	rot_mid_top(t_stack **left, t_stack **right)
{
	t_stack	*ptr;
	int		mid;
	int		index;
	int		i;

	mid = (*left)->order;
	i = 1;
	index = 0;
	ptr = *right;
	while (ptr->next)
	{
		if (mid < ptr->order && mid > ptr->next->order)
			index = i;
		ptr = ptr->next;
		i++;
	}
	if (index == 0)
	{
		push_b(left, right);
		return ;
	}
	act_mid(right, index);
}
