/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:14:44 by wthanata          #+#    #+#             */
/*   Updated: 2022/08/27 17:32:33 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rot_a(t_stack **lst, int c)
{
	t_stack	*ptr;
	t_stack	*tmp;
	int		i;

	i = count_list(lst);
	if (i < 2)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	ptr = *lst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = tmp;
	tmp->next = NULL;
	if (c == 1)
		write(1, "ra\n", 3);
}

void	rot_b(t_stack **lst, int c)
{
	t_stack	*ptr;
	t_stack	*tmp;
	int		i;

	i = count_list(lst);
	if (i < 2)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	ptr = *lst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = tmp;
	tmp->next = NULL;
	if (c == 1)
		write(1, "rb\n", 3);
}

void	rot_ab(t_stack **a, t_stack **b, int c)
{
	rot_a(a, c);
	rot_b(b, c);
	if (c == 2)
		write(1, "rr\n", 3);
}
