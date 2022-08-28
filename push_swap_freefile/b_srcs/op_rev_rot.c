/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:38:50 by wthanata          #+#    #+#             */
/*   Updated: 2022/08/27 17:32:23 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rev_rot_a(t_stack **lst, int c)
{
	t_stack	*new_bottom;
	t_stack	*ptr;
	int		i;

	i = count_list(lst);
	if (i < 2)
		return ;
	new_bottom = *lst;
	while (1)
	{
		ptr = new_bottom;
		i = count_list(&ptr);
		if (i == 2)
			break ;
		new_bottom = new_bottom->next;
	}
	new_bottom->next->next = *lst;
	*lst = new_bottom->next;
	new_bottom->next = NULL;
	if (c == 1)
		write(1, "rra\n", 4);
}

void	rev_rot_b(t_stack **lst, int c)
{
	t_stack	*new_bottom;
	t_stack	*ptr;
	int		i;

	i = count_list(lst);
	if (i < 2)
		return ;
	new_bottom = *lst;
	while (1)
	{
		ptr = new_bottom;
		i = count_list(&ptr);
		if (i == 2)
			break ;
		new_bottom = new_bottom->next;
	}
	new_bottom->next->next = *lst;
	*lst = new_bottom->next;
	new_bottom->next = NULL;
	if (c == 1)
		write(1, "rrb\n", 4);
}

void	rev_rot_ab(t_stack **a, t_stack **b, int c)
{
	rev_rot_a(a, c);
	rev_rot_b(b, c);
	if (c == 2)
		write(1, "rrr\n", 4);
}
