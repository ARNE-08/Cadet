/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:48:15 by wthanata          #+#    #+#             */
/*   Updated: 2022/08/27 14:52:28 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ck_chunk(t_stack **a, int size, int chunk_cnt)
{
	t_stack	*ptr;
	int		chunk;
	int		npch;

	chunk = ((size - 34) / 66) + 6;
	npch = size / chunk;
	ptr = *a;
	while (ptr)
	{
		if (ptr->order / npch == chunk_cnt)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int	find_top(t_stack **a, int npch, int chunk_cnt)
{
	t_stack	*ptr;
	int		top;
	int		i;

	i = 0;
	top = 0;
	ptr = *a;
	while (ptr)
	{
		if (ptr->order / npch == chunk_cnt)
		{
			top = i;
			break ;
		}
		ptr = ptr->next;
		i++;
	}
	return (top);
}

int	find_bot(t_stack **a, int npch, int chunk_cnt)
{
	t_stack	*ptr;
	int		bot;
	int		i;

	i = 0;
	bot = 0;
	ptr = *a;
	while (ptr)
	{
		if (ptr->order / npch == chunk_cnt)
			bot = i;
		ptr = ptr->next;
		i++;
	}
	return (bot);
}

void	rot_chunk_top(t_stack **a, int size, int chunk_cnt)
{
	int		top;
	int		bot;
	int		npch;

	npch = size / (((size - 34) / 66) + 6);
	top = find_top(a, npch, chunk_cnt);
	bot = find_bot(a, npch, chunk_cnt);
	if (top <= (count_list(a) - bot))
		while ((*a)->order / npch != chunk_cnt)
			rot_a(a, 1);
	else if (top > (count_list(a) - bot))
		while ((*a)->order / npch != chunk_cnt)
			rev_rot_a(a, 1);
}

void	chunk_loop(t_stack **a, t_stack **b, int size, int chunk_cnt)
{
	while (ck_chunk(a, size, chunk_cnt))
	{
		rot_chunk_top(a, size, chunk_cnt);
		if ((*a)->order > (*b)->order && (*a)->order < to_last(b)->order)
			push_b(a, b);
		else if ((*a)->order == 0 || (*a)->order == (size - 1)
			|| is_max_min(a, b, 1) || is_max_min(a, b, 0))
		{
			rot_high_top(b);
			push_b(a, b);
		}
		else
		{
			rot_mid_top(a, b);
			push_b(a, b);
		}
	}
}
