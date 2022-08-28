/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:01:45 by wthanata          #+#    #+#             */
/*   Updated: 2022/08/27 19:02:43 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	free_list(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}

void	act_sort2(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk;
	int	chunk_cnt;

	size = count_list(a) + count_list(b);
	chunk = ((size - 34) / 66) + 6;
	chunk_cnt = chunk - 1;
	while (chunk_cnt >= 0)
	{
		chunk_loop(a, b, size, chunk_cnt);
		chunk_cnt--;
	}
	if (size % chunk != 0)
	{
		chunk_cnt = chunk;
		while (*a)
		{
			chunk_loop(a, b, size, chunk_cnt);
			chunk_cnt++;
		}
	}
}

void	sort_big(t_stack **a, t_stack **b)
{
	act_sort1(a, b);
	act_sort2(a, b);
	rot_high_top(b);
	while (*b)
		push_a(a, b);
}

int	is_sort(t_stack *a)
{
	t_stack	*ptr;

	ptr = a;
	while (ptr->next)
	{
		if (ptr->order > ptr->next->order)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (1);
	a = arg_check(argc, argv);
	b = NULL;
	if (is_sort(a))
	{
		free_list(a);
		return (0);
	}
	if (count_list(&a) <= 5)
		sort_small(&a, &b);
	else
		sort_big(&a, &b);
	free_list(a);
	free_list(b);
	return (0);
}
